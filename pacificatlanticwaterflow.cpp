vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
void bfs(queue<pair<int,int>>& q,vector<vector<int>>& grey,vector<vector<int>>& arr,int n,int m)
{
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        for(int k=0;k<4;++k)
        {
            int x=temp.first+dx[k],y=temp.second+dy[k];
            if(x>=0&&x<n&&y>=0&&y<m&&grey[x][y]==0&&arr[x][y]>=arr[temp.first][temp.second])
            {
                grey[x][y]=1;
                q.push({x,y});
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
{
    int n=matrix.size(),m;
    if(!n)
        return {};
    else m=matrix[0].size();
    vector<vector<int>> pacific(n,vector<int>(m,0));
    vector<vector<int>> atlantic(n,vector<int>(m,0));
    vector<vector<int>> ret;
    queue<pair<int,int>> q1,q2;
    for(int i=0;i<n;++i)
    {
        if(!pacific[i][0])
        {
            pacific[i][0]=1;
            q1.push({i,0});
        }
        if(!atlantic[i][m-1])
        {
            atlantic[i][m-1]=1;
            q2.push({i,m-1});
        }
    }
    for(int j=0;j<m;++j)
    {
        if(!pacific[0][j])
        {
            pacific[0][j]=1;
            q1.push({0,j});
        }
        if(!atlantic[n-1][j])
        {
            atlantic[n-1][j]=1;
            q2.push({n-1,j});
        }
    }
    bfs(q1,pacific,matrix,n,m);
    bfs(q2,atlantic,matrix,n,m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(pacific[i][j]==1&&atlantic[i][j]==1)
                ret.push_back({i,j});
    return ret;

}
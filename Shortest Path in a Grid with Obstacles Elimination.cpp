int shortestPath(vector<vector<int>>& grid, int k) 
{
    int n=grid.size();
    int m=grid[0].size();
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    vector<vector<vector<int>>> grey(n,vector<vector<int>>(m,vector<int>(k+1,0)));
    queue<vector<int>> q;
    grey[0][0][k]=1;
    q.push({0,0,k,0});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        int i=temp[0];
        int j=temp[1];
        int d=temp[3];
        k=temp[2];
        if(i==n-1&&j==m-1)
            return d;
        else
            for(int t=0;t<4;++t)
            {
                int x=i+dx[t],y=j+dy[t];
                if(x<n&&x>=0&&y<m&&y>=0)
                    if(grid[x][y]==0&&grey[x][y][k]==0)
                    {
                        q.push({x,y,k,d+1});
                        grey[x][y][k]=1;
                    }
                    else if(grid[x][y]==1&&k>0&&grey[x][y][k-1]==0)
                    {
                        q.push({x,y,k-1,d+1});
                        grey[x][y][k-1]=1;
                    }
            }
    }
    return -1;
}

//DP
vector<vector<vector<int>>> memo;
vector<vector<vector<int>>> grey;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
int dp(int i, int j,int k,vector<vector<int>>& grid)
{
    if(i==grid.size()-1&&j==grid[0].size()-1)
        return 0;
    else if(memo[i][j][k]!=-1)
        return memo[i][j][k];
    else
    {
        int q=1600;
        int n=grid.size(),m=grid[0].size();
        grey[i][j][k]=1;
        for(int t=0;t<4;++t)
        {
            int x=i+dx[t],y=j+dy[t];
            if(x<n&&x>=0&&y<m&&y>=0)
                if(grid[x][y]==0&&grey[x][y][k]==0)
                    q=min(q,1+dp(x,y,k,grid));
                else if(grid[x][y]==1&&k>0&&grey[x][y][k-1]==0)
                    q=min(q,1+dp(x,y,k-1,grid));
        }        
        grey[i][j][k]=0;
        return memo[i][j][k]=q;
    }
}

int shortestPath(vector<vector<int>>& grid, int k) 
{
    int n=grid.size(),m=grid[0].size();
    memo.resize(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
    grey.resize(n,vector<vector<int>>(m,vector<int>(k+1,0)));
    int val= dp(0,0,k,grid);
    return val<1600?val:-1;
}

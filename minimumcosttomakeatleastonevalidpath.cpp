struct myComp { 
    constexpr bool operator()(vector<int> const& a,vector<int> const& b) 
        const noexcept 
    { 
        return a[2]> b[2]; 
    } 
}; 
class Solution {
public:
    int minCost(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,myComp> q;
        q.push({0,0,0});
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int ret=INT_MAX;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        while(!q.empty())
        {
            vector<int> temp=q.top();
            q.pop();
            int i =temp[0],j=temp[1],d=temp[2];
            if(i==n-1&&j==m-1)
                break;
            else
                for(int k=1;k<=4;++k)
                {
                    int x=i+dx[k-1],y=j+dy[k-1];
                    if(x<n&&x>=0&&y>=0&&y<m)
                        if(grid[i][j]==k&&dist[x][y]>d)
                        {
                            dist[x][y]=d;
                            q.push({x,y,d});
                        }
                        else if(dist[x][y]>d+1)
                        {
                            dist[x][y]=d+1;
                            q.push({x,y,d+1});
                        }
                }
        }
        return dist[n-1][m-1];
    }
};
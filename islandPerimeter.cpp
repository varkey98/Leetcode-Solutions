class Solution {
public:
    vector<vector<int>> grey;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        int q=0;
        grey[i][j]=1;
        if(i+1<grid.size()&&grid[i+1][j]==1)
        {
            ++q;
            if(grey[i+1][j]==-1)
                dfs(i+1,j,grid);
        }
        if(j+1<grid[0].size()&&grid[i][j+1]==1)
        {
            ++q;
            if(grey[i][j+1]==-1)
                dfs(i,j+1,grid);
        }
        if(i>0&&grid[i-1][j]==1)
        {
            ++q;
            if(grey[i-1][j]==-1)
                dfs(i-1,j,grid);
        }
        if(j>0&&grid[i][j-1]==1)
        {
            ++q;
            if(grey[i][j-1]==-1)
                dfs(i,j-1,grid);
        }
        grey[i][j]=q;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int ret=0;
        int n=grid.size();
        int m=grid[0].size();
        grey.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid);
                    break;
                }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                //cout<<grey[i][j]<<" ";
                switch(grey[i][j])
                {
                    case 1:ret+=3;
                        break;
                    case 2:ret+=2;
                        break;
                    case 3:ret+=1;
                        break;
                    case 0:ret+=4;
                        break;
                    default:ret+=0;
                }
            }
            //cout<<endl;
        }
        return ret;
    }
};
int dfs_visit(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& grey)//O(N^4)
{
	grey[i][j]=1;
	if(grid[i][j]==0)
		return 0;
	else
	{
		int q=1;
		if(i+1<grid.size()&&!grey[i+1][j])
			q+=dfs_visit(i+1,j,grid,grey);
		if(j+1<grid[0].size()&&!grey[i][j+1])
			q+=dfs_visit(i,j+1,grid,grey);
		if(i>0&&!grey[i-1][j])
			q+=dfs_visit(i-1,j,grid,grey);
		if(j>0&&!grey[i][j-1])
			q+=dfs_visit(i,j-1,grid,grey);
		return q;
	}
}
int largestIsland(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int ret=0;
    if(!n)
    	return 0;
    for(int i=0;i<n;++i)
    	for(int j=0;j<n;++j)
    		if(grid[i][j]==0)
    		{
    			vector<vector<int>> grey(n,vector<int>(n,0));
    			grid[i][j]=1;
    			ret=max(ret,dfs_visit(i,j,grid,grey));
    			grid[i][j]=0;
    		}
    return ret;
}
///O(N^2) algorithm
int island=0;
vector<vector<int>> grey;
queue<pair<int,int>> q;
int dfs_visit(int i, int j,vector<vector<int>>& grid)
{
	grey[i][j]=1;
	if(grid[i][j]==0)
		return 0;
	else
	{
		int q=1;
		grid[i][j]=island;
		if(i+1<grid.size()&&!grey[i+1][j])
			q+=dfs_visit(i+1,j,grid);
		if(j+1<grid[0].size()&&!grey[i][j+1])
			q+=dfs_visit(i,j+1,grid);
		if(i>0&&!grey[i-1][j])
			q+=dfs_visit(i-1,j,grid);
		if(j>0&&!grey[i][j-1])
			q+=dfs_visit(i,j-1,grid);
		return q;
	}
}
int* dfs(vector<vector<int>>& grid)
{
	int n=grid.size();
	grey.resize(n,vector<int>(n,0));
	int* ret=(int*)calloc(n*n+1,sizeof(int));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(grey[i][j]==0&&grid[i][j]==1)
			{
				++island;
				ret[island]=dfs_visit(i,j,grid);
				ret[0]=max(ret[0],ret[island]);
			}
			else if(grid[i][j]==0)
                q.push({i,j});
	return ret;
}
int largestIsland(vector<vector<int>>& grid)
{
	int n=grid.size();
	int* ret=dfs(grid);
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		int i=t.first,j=t.second;
		int val=1;
		set<int> s;
		s.insert(0);
		if(i+1<n&&s.find(grid[i+1][j])==s.end())
		{
			val+=ret[grid[i+1][j]];
			s.insert(grid[i+1][j]);
		}
		if(j+1<n&&s.find(grid[i][j+1])==s.end())
		{
			val+=ret[grid[i][j+1]];
			s.insert(grid[i][j+1]);
		}
		if(i>0&&s.find(grid[i-1][j])==s.end())
		{
			val+=ret[grid[i-1][j]];
			s.insert(grid[i-1][j]);
		}
		if(j>0&&s.find(grid[i][j-1])==s.end())
		{
			val+=ret[grid[i][j-1]];
			s.insert(grid[i][j-1]);
		}
		ret[0]=max(ret[0],val);

	}
	return ret[0];
}

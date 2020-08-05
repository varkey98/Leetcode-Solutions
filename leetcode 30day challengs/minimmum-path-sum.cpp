int m,n;
int DP_DFS(int x,int y,vector<vector<int>> v,int** arr)
{
	if(x>=m||y>=n)
		return 0;
	else if(x==m-1&&y==n-1)
		return v[y][x];
	else if(arr[y][x])
		return arr[y][x];
	else
	{
		if(x+1<m&&y+1<n)
			arr[y][x]=min(DP_DFS(x+1,y,v,arr),DP_DFS(x,y+1,v,arr))+v[y][x];
		else if(x+1<m)
			arr[y][x]=DP_DFS(x+1,y,v,arr)+v[y][x];
		else
			arr[y][x]=DP_DFS(x,y+1,v,arr)+v[y][x];
		return arr[y][x];
	}
	
}
int minPathSum(vector<vector<int>>& grid)
{
    m=grid[0].size();
    n=grid.size();
    int** arr=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;++i)
    	arr[i]=(int*)calloc(m,sizeof(int));
	return DP_DFS(0,0,grid,arr);
}
// or
int minPathSum(vector<vector<int>>& grid)
{
	int m=grid[0].size(),n=grid.size();
	for(int y=grid.size()-1;y>=0;--y)
		for(int x=grid[0].size()-1;x>=0;--x)
		{
			if(x==m-1&&y==n-1)
				continue;
			else  if(y==n-1)
				grid[y][x]+=grid[y][x+1];
			else if(x==m-1)
				grid[y][x]+=grid[y+1][x];
			else
				grid[y][x]+=min(grid[y][x+1],grid[y+1][x]);
		}
		return grid[0][0];
}
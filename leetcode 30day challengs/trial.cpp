int DP_DFS(int x,int y,vector<vector<int>> v,int** arr])
{
	if(x>=m||y>=n)
		return 0;
	else if(x==m-1&&y==n-1)
		return v[y][x];
	else if(arr[y][x])
		return v[y][x];
	else
	{
        arr[y][x]=true;
		if(x+1<m&&y+1<n)
			v[y][x]+=min(DP_DFS(x+1,y,v,arr),DP_DFS(x,y+1,v,arr));
		else if(x+1<m)
			v[y][x]+=DP_DFS(x+1,y,v,arr);
		else
			v[y][x]+=DP_DFS(x,y+1,v,arr);
		return v[y][x];
	}
	
}
int minPathSum(vector<vector<int>>& grid)
{
    m=grid[0].size();
    n=grid.size();
    int** arr=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;++i)
    	arr[i]=(int)calloc(m,sizeof(int));
	return DP_DFS(0,0,grid,arr[][m]);
}
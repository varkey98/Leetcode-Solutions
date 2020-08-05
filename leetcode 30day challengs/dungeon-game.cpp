int DFS(vector<vector<int>>& grid,int x,int y,int m,int n,int** arr)
{
	if(x>=m||y>=n)
		return INT_MIN;
	else if(x==m-1&&y==n-1)
    {
        if(grid[y][x]<=0)
            arr[y][x]=1-grid[y][x];
        else arr[y][x]=1;
		return arr[y][x];
    }
	else if(arr[y][x]!=0)
		return arr[y][x];
	else
	{
        int t;
		if(x+1<m&&y+1<n)
			t=min(DFS(grid,x+1,y,m,n,arr),DFS(grid,x,y+1,m,n,arr));
		else if(x+1<m)
			t=DFS(grid,x+1,y,m,n,arr);
		else
			t=DFS(grid,x,y+1,m,n,arr);
		if(t<0)
			arr[y][x]=1-t;
		else  arr[y][x]=t;
		if(grid[y][x]<0)
			arr[y][x]-=grid[y][x];
		else if(grid[y][x]>=arr[y][x])
			arr[y][x]=1;
		else if(grid[y][x]<arr[y][x])
			arr[y][x]-=grid[y][x];
		return arr[y][x];
	}
}
int calculateMinimumHP(vector<vector<int>>& grid) 
{
	int n=grid.size();
	int m=grid[0].size();
	int** arr=(int**)calloc(n,sizeof(int*));
	for(int i=0;i<n;++i)
		arr[i]=(int*)calloc(m,sizeof(int));
    
        //vector<vector<long int>> arr(n, vector<long int>(m, 0));
	 return DFS(grid,0,0,m,n,arr);
} 
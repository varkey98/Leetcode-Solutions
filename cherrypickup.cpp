vector<vector<vector<vector<int>>>> memo;
int dp(int i1,int j1,int i2,int j2,vector<vector<int>>& grid)
{
	if(i1>=grid.size()||j1>=grid.size()||grid[i1][j1]==-1||i2>=grid.size()||j2>=grid.size()||grid[i2][j2]==-1)
		return -1000;
	if(memo[i1][j1][i2][j2]!=-1)
		return memo[i1][j1][i2][j2];
	int q=0;
	if(i1==i2&&j1==j2)
		q=grid[i1][j1];
	else
		q=grid[i1][j1]+grid[i2][j2];
	if(i1==grid.size()-1&&j1==grid.size()-1&&i2==grid.size()-1&&j2==grid.size()-1)
		return grid[i1][j1];
	else
		{
			int val=-1000;
			val=max(val,q+dp(i1+1,j1,i2+1,j2,grid));
			val=max(val,q+dp(i1+1,j1,i2,j2+1,grid));
			val=max(val,q+dp(i1,j1+1,i2+1,j2,grid));
			val=max(val,q+dp(i1,j1+1,i2,j2+1,grid));
			return memo[i1][j1][i2][j2]=val;
		}	
}
int cherryPickup(vector<vector<int>>& grid) 
{
	int n=grid.size();
	memo.resize(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
    int val=dp(0,0,0,0,grid);
    if(val>0)
        return val;
    else
	return 0; 
}
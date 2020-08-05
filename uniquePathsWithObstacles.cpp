int dp(int i,int j,vector<vector<int>>& grid)
{
	if(i>=grid.size()||j>=grid[0].size())
		return 0;
	if(i==grid.size()-1&&j==grid[0].size()-1)
		if(grid[i][j])
            return 0;
        else return 1;
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(grid[i][j]==1)
		return 0;
	return memo[i][j]=dp(i,j+1,grid)+dp(i+1,j,grid);
}
int uniquePathsWithObstacles(vector<vector<int>>& g) 
{
    memo.resize(g.size(),vector<int>(g[0].size(),-1));
    return dp(0,0,g);
}
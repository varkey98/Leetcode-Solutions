vector<vector<vector<int>>> memo;
int dp(int i,int r1,int r2,vector<vector<int>>& grid)
{
	if(r1<0||r2<0||r1>=grid[0].size()||r2>=grid[0].size()||i>=grid.size())
		return 0;
	if(memo[i][r1][r2]!=-1)
		return memo[i][r1][r2];
	int q=0;
		for(int j=-1;j<=1;++j)
            for(int k=-1;k<=1;++k)
			    q=max(q,dp(i+1,r1+j,r2+k,grid));
    memo[i][r1][r2]= q+grid[i][r1]+((r1==r2)?0:grid[i][r2]);
	return memo[i][r1][r2];

}
int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    if(n)
    {
    	int m=grid[0].size();
    	memo.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
    	if(m)
    		return dp(0,0,m-1,grid);
    }
    return 0;
}
vector<vector<int>> grey;
void params(int* n,int* m,int* c,vector<vector<int>>& grid)
{
	for(int i=0;i<grid.size();++i)
		for(int j=0;j<grid[0].size();++j)
			if(grid[i][j]==1)
			{
				*n=i;
				*m=j;
			}
			else if(grid[i][j]==-1)
				*c=*c+1;
}
int dp(int i,int j,int c,vector<vector<int>>& grid,int val)
{
	if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
		return 0;
	/*if(memo[i][j]!=-1)
		return memo[i][j];*/
	val+=1;
	if(grid[i][j]==2)
		if(val==c)
			return 1;
		else return 0;
	if(grid[i][j]==-1)
		return 0;
	grey[i][j]=1;
	int q=0;
	if(i+1<grid.size())
		if(!grey[i+1][j])
			q+=dp(i+1,j,c,grid,val);
	if(j+1<grid[0].size())
		if(!grey[i][j+1])
			q+=dp(i,j+1,c,grid,val);
	if(i>=1)
		if(!grey[i-1][j])
			q+=dp(i-1,j,c,grid,val);
	if(j>=1)
		if(!grey[i][j-1])
			q+=dp(i,j-1,c,grid,val);
	grey[i][j]=0;
	return q;
}
int uniquePathsIII(vector<vector<int>>& grid) 
{
    int n,m,c=0;
    params(&n,&m,&c,grid);
    //cout<<c<<endl;
    c=grid.size()*grid[0].size()-c;
    //cout<<c;
    //memo.resize(grid.size(),vector<int>(grid[0].size(),-1));
    grey.resize(grid.size(),vector<int>(grid[0].size(),0));
    return dp(n,m,c,grid,0);
}
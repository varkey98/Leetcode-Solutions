vector<vector<string>> ret;
void makeGrid(vector<vector<int>>& grid,int r ,int c)
{
	int n=grid.size();
	for(int i=0;i<n;++i)
	{
		if(i!=c)
			grid[r][i]=-1;
		if(i>r)
			grid[i][c]=-1;
	}
	int left=c-1;
	int right=c+1;
	for(int i=r+1;i<n;++i)
	{
		if(left>=0)
		{
			grid[i][left]=-1;
			left--;
		}
		if(right<n)
		{
			grid[i][right]=-1;
			right++;
		}
		if(left<0&&right>=n)
			break;
	}
}
void dfs(int r,int n,vector<vector<int>> grid,vector<string> res)
{
	if(r>=n)
		ret.push_back(res);
	else
	{
		string s(n,'.');
		for(int i=0;i<n;++i)
			if(grid[r][i]==0)
			{
				vector<vector<int>> temp(grid);
				temp[r][i]=1;
				s[i]='Q';
				makeGrid(temp,r,i);
				res.push_back(s);
				dfs(r+1,n,temp,res);
                s[i]='.';
                res.pop_back();
			}
	}
}
vector<vector<string>> solveNQueens(int n) 
{
	vector<vector<int>> grid(n,vector<int>(n,0)); 
    dfs(0,n,grid,{});
	return ret;  
}
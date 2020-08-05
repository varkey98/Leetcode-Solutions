int island=0;
vector<vector<int>> grey;
void dfs_visit(int i,int j,vector<vector<char>>& arr)
{
	grey[i][j]=1;
	if(i+1<arr.size()&&!grey[i+1][j]&&arr[i+1][j]=='1')
		dfs_visit(i+1,j,arr);
	if(j+1<arr[0].size()&&!grey[i][j+1]&&arr[i][j+1]=='1')
		dfs_visit(i,j+1,arr);
	if(i>0&&!grey[i-1][j]&&arr[i-1][j]=='1')
		dfs_visit(i-1,j,arr);
	if(j>0&&!grey[i][j-1]&&arr[i][j-1]=='1')
		dfs_visit(i,j-1,arr);
}
void dfs(vector<vector<char>>& arr)
{
    grey.resize(arr.size(),vector<int>(arr[0].size(),0));
	for(int i=0;i<arr.size();++i)
		for(int j=0;j<arr[0].size();++j)
			if(arr[i][j]=='1'&&!grey[i][j])
			{
				++island;
				dfs_visit(i,j,arr);
			}
}
int numIslands(vector<vector<char>>& grid) 
{
    if(!grid.size()||!grid[0].size())
        return 0;
    dfs(grid);
    return island;
}
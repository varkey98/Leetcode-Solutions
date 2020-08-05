bool flag=false;
vector<vector<int>> group;
void dfs(stack<pair<int,int>>& st,vector<vector<bool>>& r,vector<vector<bool>>& c,vector<vector<bool>>& g,vector<vector<int>>& grid)
{
	if(st.empty())
		flag=true;
	else
	{
		auto temp=st.top();
		st.pop();
		int i=temp.first,j=temp.second;
		for(int k=1;k<=9;++k)
			if((g[group[i][j]][k]==false)&&(r[i][k]==false)&&(c[j][k]==false))
			{
				grid[i][j]=k;
				g[group[i][j]][k]=true;
				r[i][k]=true;
				c[j][k]=true;
				dfs(st,r,c,g,grid);
				if(flag)
					return;
                grid[i][j]=0;
				g[group[i][j]][k]=false;
				r[i][k]=false;
				c[j][k]=false;
			}
		st.push(temp);
	}
}
void solveSudoku(vector<vector<char>>& board) 
{
    group.resize(9,vector<int>(9,0));
    vector<vector<int>> init={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
    int count=0;
    for(auto x:init)
    {
    	for(int i=x[0];i<x[0]+3;++i)
    		for(int j=x[1];j<x[1]+3;++j)
    			group[i][j]=count;
    	++count;
    }
    stack<pair<int,int>> st;
    vector<vector<bool>> row(9,vector<bool>(10,false));
    vector<vector<bool>> col(9,vector<bool>(10,false));
    vector<vector<bool>> g(9,vector<bool>(10,false));
    vector<vector<int>> grid(9,vector<int>(9));
    for(int i=0;i<9;++i)
    	for(int j=0;j<9;++j)
    		if(board[i][j]!='.')
    		{
    			grid[i][j]=board[i][j]-'0';
    			g[group[i][j]][grid[i][j]]=true;
    			row[i][grid[i][j]]=true;
    			col[j][grid[i][j]]=true;
    		}
    		else st.push({i,j});
    dfs(st,row,col,g,grid);
    for(int i=0;i<9;++i)
    	for(int j=0;j<9;++j)
    		if(board[i][j]=='.')
    			board[i][j]=grid[i][j]+'0';
}
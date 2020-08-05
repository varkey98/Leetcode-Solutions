vector<vector<int>> grey;
bool dfs_visit(int i,int j,vector<vector<char>>& board,bool flag)
{
    grey[i][j]=1;
    int q= i==0||j==0||i==board.size()-1||j==board[0].size()-1?true:false;
    if(i+1<board.size()&&!grey[i+1][j]&&board[i+1][j]=='O')
        q+=dfs_visit(i+1,j,board,flag);
    if(j+1<board[0].size()&&!grey[i][j+1]&&board[i][j+1]=='O')
        q+=dfs_visit(i,j+1,board,flag);
    if(i>0&&!grey[i-1][j]&&board[i-1][j]=='O')
        q+=dfs_visit(i-1,j,board,flag);
    if(j>0&&!grey[i][j-1]&&board[i][j-1]=='O')
        q+=dfs_visit(i,j-1,board,flag);
    if(flag)
        board[i][j]='X';
    return q;
}
void dfs(vector<vector<char>>& board)
{
    int n=board.size();
    if(n)
    {
        vector<pair<int,int>> ret;
        int m=board[0].size();
        grey.resize(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(!grey[i][j]&&board[i][j]=='O')
                    if(!dfs_visit(i,j,board,false))
                        ret.push_back({i,j});
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                grey[i][j]=0;
        for(auto x:ret)
            dfs_visit(x.first,x.second,board,true);
    }
}
void solve(vector<vector<char>>& board) 
{
        dfs(board);
}

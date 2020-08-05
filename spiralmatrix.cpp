vector<vector<int>> grey;
vector<int> ret;
void dfs(vector<vector<int>>& m,int i,int j,int dir)
{
    grey[i][j]=1;
    ret.push_back(m[i][j]);
    if(dir==6)
    {
        if(j<m[0].size()-1&&!grey[i][j+1])
            dfs(m,i,j+1,6);
        else if(i+1<m.size()&&!grey[i+1][j])
            dfs(m,i+1,j,2);
    }
    if(dir==2)
    {
       if(i+1<m.size()&&!grey[i+1][j])
            dfs(m,i+1,j,2); 
        else if(j>0&&!grey[i][j-1])
            dfs(m,i,j-1,4);
    }
    if(dir==4)
    {
        if(j>0&&!grey[i][j-1])
            dfs(m,i,j-1,4);
        else if(i>0&&!grey[i-1][j])
            dfs(m,i-1,j,8);
    }
    if(dir==8)
    {
        if(i>0&&!grey[i-1][j])
            dfs(m,i-1,j,8);
        else if(j<m[0].size()-1&&!grey[i][j+1])
            dfs(m,i,j+1,6);
    }

}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(!matrix.size()||!matrix[0].size())
        return ret;
    grey.resize(matrix.size(),vector<int>(matrix[0].size(),0));
    dfs(matrix,0,0,6);
    return ret;
}
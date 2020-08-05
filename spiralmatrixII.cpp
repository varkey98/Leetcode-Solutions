vector<vector<int>> grey;
vector<vector<int>> ret;
void dfs(int i,int j,int dir,int val,int n)
{
    grey[i][j]=1;
    ret[i][j]=val;
    if(dir==6)
    {
        if(j<n-1&&!grey[i][j+1])
            dfs(i,j+1,6,val+1,n);
        else if(i+1<n&&!grey[i+1][j])
            dfs(i+1,j,2,val+1,n);
    }
    if(dir==2)
    {
       if(i+1<n&&!grey[i+1][j])
            dfs(i+1,j,2,val+1,n); 
        else if(j>0&&!grey[i][j-1])
            dfs(i,j-1,4,val+1,n);
    }
    if(dir==4)
    {
        if(j>0&&!grey[i][j-1])
            dfs(i,j-1,4,val+1,n);
        else if(i>0&&!grey[i-1][j])
            dfs(i-1,j,8,val+1,n);
    }
    if(dir==8)
    {
        if(i>0&&!grey[i-1][j])
            dfs(i-1,j,8,val+1,n);
        else if(j<n-1&&!grey[i][j+1])
            dfs(i,j+1,6,val+1,n);
    }

}
vector<vector<int>> generateMatrix(int n) {
    if(!n)
        return ret;
    grey.resize(n,vector<int>(n,0));
    ret.resize(n,vector<int>(n,0));
    dfs(0,0,6,1,n);
    return ret;
}
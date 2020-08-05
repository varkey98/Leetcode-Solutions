vector<vector<int>> grey;
vector<vector<int>> memo;
int dfs(int i,int j,vector<vector<int>>& m)
{
    if(memo[i][j]!=-1)
    	return memo[i][j];
    grey[i][j]=1;
    int q=INT_MIN;
    if(i+1<m.size()&&!grey[i+1][j]&&m[i][j]<m[i+1][j])
    	q=max(q,1+dfs(i+1,j,m));
    if(j+1<m[0].size()&&!grey[i][j+1]&&m[i][j]<m[i][j+1])
    	q=max(q,1+dfs(i,j+1,m));
    if(i>0&&!grey[i-1][j]&&m[i][j]<m[i-1][j])
    	q=max(q,1+dfs(i-1,j,m));
    if(j>0&&!grey[i][j-1]&&m[i][j]<m[i][j-1])
    	q=max(q,1+dfs(i,j-1,m));
    if(q==INT_MIN)
    	q=1;
    grey[i][j]=0;
    return memo[i][j]=q;
}
int longestIncreasingPath(vector<vector<int>>& arr) 
{
    int n=arr.size();
    if(!n)
        return 0;
    int m=arr[0].size();
    if(!m)
        return 0;
    int ret=0;
	grey.resize(n,vector<int>(m,0)); 
	memo.resize(n,vector<int>(m,-1));  
	for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            ret=max(ret,dfs(i,j,arr));
    return ret;
}
vector<vector<int>> memo;
int dp(int i,int j,vector<vector<int>>& A){
    if(i==A.size())
        return 0;
    if(i>=A.size()||j>=A.size()||j<0)
        return 500;
    if(memo[i][j]!=-1)
        return memo[i][j];
    int q=500;
    for(int p=-1;p<=1;++p)
        q=min(q,dp(i+1,j+p,A));
    return memo[i][j]=A[i][j]+q;
}

int minFallingPathSum(vector<vector<int>>& A) {
    int q=INT_MAX;
    memo.resize(A.size(),vector<int>(A.size(),-1));
    for(int i=0;i<A.size();++i)
        q=min(q,dp(0,i,A));
    return q;
}
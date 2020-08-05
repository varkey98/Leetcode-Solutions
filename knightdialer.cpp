#define mod 1000000007
vector<vector<vector<int>>> memo;
int dp(int i,int j,int n)
{
    if(i==3&&j==1)
        if(n==1)
            return 1;
        else
            return memo[i][j][n]=dp(i-2,j-1,n-1)+dp(i-2,j+1,n-1);
    if(i<0||j<0||j>=3||i>=3)
        return 0;
    if(n==1)
        return 1;
    if(memo[i][j][n]!=-1)
        return memo[i][j][n];
    else
    {
        long q=(long)dp(i-2,j-1,n-1)+dp(i-2,j+1,n-1)+dp(i-1,j-2,n-1)+dp(i-1,j+2,n-1)+dp(i+1,j-2,n-1)+dp(i+1,j+2,n-1)+dp(i+2,j-1,n-1)+dp(i+2,j+1,n-1);
        return memo[i][j][n]=q%mod;
    }
}
int knightDialer(int n) 
{
    memo.resize(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
    long q=0;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            q+=dp(i,j,n);
    q+=dp(3,1,n);
    return q%mod;
}

int* memo;
int dp(int n)
{
    if(n==0||n==1)
        return 1;
    else if(memo[n])
        return memo[n];
    else
    {
        int q=0;
        for(int i=1;i<=n;++i)
            q+=dp(i-1)*dp(n-i);
        return memo[n]=q;
    }
}
int numTrees(int n)
{
memo=(int*)calloc(n+1,sizeof(int));
return dp(n);
}
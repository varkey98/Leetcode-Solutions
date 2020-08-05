vector<int> memo;
int dp(int i,int d,vector<int>& arr)
{
    if(i>=arr.size()||i<0)
        return 0;
    if(memo[i]!=-1)
        return memo[i];
    int q=1;
    for(int  j=i+1;j<arr.size()&&j-i<=d;++j)
        if(arr[i]>arr[j])
            q=max(q,1+dp(j,d,arr));
        else break;
    for(int j=i-1;j>=0&&i-j<=d;--j)
        if(arr[i]>arr[j])
            q=max(q,1+dp(j,d,arr));
        else break;
    return memo[i]=q;                
}
int maxJumps(vector<int>& arr, int d) 
{
    int n=arr.size();
    memo.resize(n,-1);
    int ret=0;
    for(int i=0;i<n;++i)
        ret=max(ret,dp(i,d,arr));
    return ret;
}

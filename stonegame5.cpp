bool dp(int p,int n,vector<int>& arr)
{
    if(memo[p][n]!=-1)
        return memo[p][n];
    int q=0;
    for(int x:arr)
        if(x<=n)
        {
            q+=!dp(!p,n-x,arr);
            if(q>0)
                break;
        }
    return memo[p][n]=q;
}
bool winnerSquareGame(int n) 
{
    vector<int> arr;
    for(int i=1;i<=(int)sqrt(n);++i)
        arr.push_back(i*i);
    memo.resize(2,vector<int>(n+1,-1));
    return dp(0,n,arr);
}
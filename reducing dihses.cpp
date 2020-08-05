vector<vector<int>> memo;
int dp(int i,int t,vector<int>& arr)
{
    if(i>=arr.size())
        return 0;
    if(memo[i][t]!=-1)
        return memo[i][t];
    int not_taken=dp(i+1,t,arr);
    int taken=arr[i]*t+dp(i+1,t+1,arr);
    return memo[i][t]=max(taken,not_taken);
}
int maxSatisfaction(vector<int>& arr) 
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    memo.resize(n,vector<int>(n+1,-1));
    return dp(0,1,arr);
}
#define mod 1000000007
vector<vector<int>> memo;
int dp(int i,int steps,int n)
{
	if(i>=n||i<0)
		return 0;
	if(steps==0)
		if(i==0)
			return 1;
		else return 0;
	else if(memo[i][steps]!=-1)
		return memo[i][steps];
	else
	{ 	
		long q=dp(i+1,steps-1,n)+dp(i-1,steps-1,n)+dp(i,steps-1,n);
		return memo[i][steps]=q%mod;
	}
}
int numWays(int steps, int arrLen) 
{
    memo.resize(arrLen,vector<int>(steps+1,-1));
    return dp(0,steps,arrLen);
} 
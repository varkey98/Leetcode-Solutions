//vector<vector<int>> memo;//i is the index of the song getting selected.
int dp(int i,int l,int k,vector<int> pi)
{
	if(i>=l)
    {
        for(int x:pi)
            if(x==-1)
                return 0;
		return 1;
    }
	int q=0;
	for(int j=0;j<pi.size();++j)
		if(pi[j]==-1||i-pi[j]-1>=k)
		{
			int temp=pi[j];
			pi[j]=i;
			q+=dp(i+1,l,k,pi);
			pi[j]=temp;
		}
	return q;

}
int numMusicPlaylists(int N, int L, int K) 
{
    vector<int> pi(N,-1);
    return dp(0,L,K,pi);
}
// combinatorics solution
#define mod 1000000007
int numMusicPlaylists(int N, int L, int K) 
{
	vector<vector<int>> dp(L+1,vector<int>(N+1,0));
	dp[0][0]=1;
	for(int i=1;i<=L;++i)
		for(int n=1;n<=N;++n)
		{
            long x=0;
			if(n<=i)
				x=((long)N-n+1)*dp[i-1][n-1];
			if(n>K)
				x+=((long)n-K)*dp[i-1][n];
			dp[i][n]=x%mod;
		}
    return dp[L][N];
}
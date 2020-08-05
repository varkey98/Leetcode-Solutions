int dp(int i,int j,vector<int>&s,int k)
{
	if(j-i+1<=1)
		return 0;
	if(j-1+1<k)
		return 4000;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int count=0;
	int val=0;
	int q=4000;
	for(int p=i;p<=j;++p)
	{
		val+=s[p];
		++count;
		if(count==k)
		{
			int temp=s[p];
			s[p]=val;
			int ret=dp(i,p-k,s,k)+dp(p,j,s,k);
			s[p]=temp;
			temp=s[p-k+1];
			s[p-k+1]=val;
			ret=min(ret,dp(i,p-k+1,s,k)+dp(p+1,j,s,k));
			q=min(q,ret);
			s[p-k+1]=temp;
			val-=s[p-k+1];
			--count;
		}
	}
	return memo[i][j]=q;
}
int mergeStones(vector<int>& stones, int K) 
{
	memo.resize(stones.size(),vector<int>(stones.size(),-1));
	return dp(0,stones.size()-1,stones,K);
}
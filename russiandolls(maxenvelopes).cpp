vector<int> memo;//O(n2) dp
int ret=1;
int dp(int i,vector<vector<int>>& e)
{
    if(memo[i]!=-1)
        return memo[i];
	int q=INT_MIN;
	for(int j=0;j<e.size();++j)
	{
		if(j==i)
			continue;
		if(e[i][0]<e[j][0]&&e[i][1]<e[j][1])
			q=max(q,1+dp(j,e));
	}
	if(q==INT_MIN)
		q=1;
	ret=max(ret,q);
	return memo[i]=q;
}
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    if(!envelopes.size())
        return 0;
    memo.resize(envelopes.size(),-1);
    for(int i=0;i<envelopes.size();++i)
        dp(i,envelopes);
    return ret;
}
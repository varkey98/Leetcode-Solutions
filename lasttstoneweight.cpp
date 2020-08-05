//TLE.
vector<vector<int>> memo;
int  dp(vector<int>& s,int i,int sum1,int sum2,int mask)
{
	if(i>=s.size())
		return abs(sum1-sum2);
	if(memo[mask][i]!=-1)
		return memo[mask][i];
	int taken=dp(s,i+1,sum1+s[i],sum2,mask|1<<i);
	int not_taken=dp(s,i+1,sum1,sum2+s[i],mask);
	return memo[mask][i]=min(taken,not_taken);
}
int lastStoneWeightII(vector<int>& stones) {
	int allmask=(1<<stones.size())-1;
	memo.resize(allmask,vector<int>(stones.size(),-1));
    return dp(stones,0,0,0,0);
}
map<string,int> memo;
int  dp(vector<int>& s,int i,int sum1,int sum2,int flag)
{
	if(i>=s.size())
		return abs(sum1-sum2);
	string s=to_string(i)+"|"+to_string(sum1);
	if(memo.find(s)!=memo.end())
		return memo[s];
	int taken=dp(s,i+1,sum1+s[i],sum2,mask|1<<i);
	int not_taken=dp(s,i+1,sum1,sum2+s[i],mask);
	int q=min(taken,not_taken);
	return memo[s]=q;
}
int lastStoneWeightII(vector<int>& stones) {

    return dp(stones,0,0,0,0);
}
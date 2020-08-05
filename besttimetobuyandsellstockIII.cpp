vector<vector<vector<int>>> memo;
int dp(int day,int k,vector<int>& prices,int bought,bool flag)
{
	if(k<=0&&bought==-1)
		return 0;
	else if(day>=prices.size()&&bought!=-1)
		return -150;
	else if(day>=prices.size())
		return 0;
	if(memo[day][flag][k]!=INT_MIN)
		return memo[day][flag][k];
	int q=dp(day+1,k,prices,bought,flag);
	if(flag)
		memo[day][flag][k]= max(q,prices[day]+dp(day+1,k,prices,-1,false));
	else
	    memo[day][flag][k]= max(q,dp(day+1,k-1,prices,prices[day],true)-prices[day]);
	return memo[day][flag][k];
}
int maxProfit(vector<int>& prices) 
{
	memo.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,INT_MIN)));
	return dp(0,2,prices,-1,false);
    return 0;
}
vector<int> memo;//naive DP doesn't work because for same index pos will be different for differetn calls which is a problem.
//this is naive recurion though,giving TLE.
//// even the count of stops till now wont give proper result because of different positions. The problem is that we cant memoize
// the distance unlike in the coin change where we could do the amount.
vector<vector<int>> memo;
int dp(int i,int c,int pos,int target,vector<vector<int>>& st)
{
	if(pos>=target)
		return 0;
	else if(i>=st.size()||pos<st[i][0])
		return 555;
	/*else if(memo[i][c]!=-1)
		return memo[i][c];*/
	else
        return memo[i][c]=min(dp(i+1,c,pos,target,st),1+dp(i+1,c+1,pos+st[i][1],target,st));
}
int minRefuelStops(int target, int startFuel, vector<vector<int>>& station) 
{
	int ret=555;
	memo.resize(station.size()+1,vector<int>(500,-1));
	ret=dp(0,0,startFuel,target,station);
	return ret<501?ret:-1;
}
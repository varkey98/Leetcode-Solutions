#define k 5555555
vector<vector<int>> memo;
int dp(int i,int day,vector<int>& arr)
{
	if(i>=arr.size()&&day==0)
		return 0;
	else if(i>=arr.size()||day==0)
		return k;
    else if(memo[i][day]!=-1)
        return memo[i][day];
	else
	{
        int q=INT_MAX,val=INT_MIN;
        for(int j=i;j<arr.size();++j)
        {
            val=max(val,arr[j]);
            q=min(q,val+dp(j+1,day-1,arr));
        }
        return memo[i][day]=q;
    }
}
int minDifficulty(vector<int>& jobDifficulty, int d)
{
    memo.resize(jobDifficulty.size(),vector<int>(d+1,-1));
    int ret=dp(0,d,jobDifficulty);
    return ret<k?ret:-1;
}
vector<int> memo;// gives tle  O(n^2)
int dp(int index,vector<int>& nums)
{
	if(index>=nums.size()-1)
		return 0;
	if(memo[index]!=-1)
		return memo[index];
	else
	{
		int q=nums.size()+20;
		for(int i=1;i<=nums[index];++i)
			q=min(q,1+dp(index+i,nums));
		return memo[index]=q;
	}
}
int jump(vector<int>& nums) 
{
    memo.resize(nums.size(),-1);
    return dp(0,nums);
}
//O(n^2)Bottom-UP DP
int jump(vector<int>& nums)
{
	int* dp=(int*)calloc(nums.size(),sizeof(int));
	for(int i=nums.size()-2;i>=0;--i)
		if(i+nums[i]>=nums.size()-1)
			dp[i]=1;
		else
		{
			int q=nums.size()+10;
			for(int j=1;j<=nums[i];++j)
				q=min(q,1+dp[j+index]);
			dp[i]=q;
		}
	return dp[0];
}
int jump(vector<int>& n)// working O(N) BFS.
{
	int start=0;
	int end=n[start];
	int count=1;
	if(n.size()==1)
		return 0;
	while(end<n.size()-1)
	{
        int tend=end;
		for(int i=start+1;i<=end;++i)
			if(i+n[i]>tend)
				tend=i+n[i];
		count+=1;
		start=end;
		end=tend;
	}
	return count;	
}
map<vector<int>,int> memo;//TLE
int dp(vector<int>& nums)
{
	if(nums.size()==0)
		return 0;
	if(nums.size()==1)
		return nums[0];
	if(memo.find(nums)!=memo.end())
		return memo[nums];
	int q=INT_MIN;
	for(int i=0;i<nums.size();++i)
	{
		int left=i-1<0?1:nums[i-1];
		int right=i+1>=nums.size()?1:nums[i+1];
		vector<int> temp=nums;
		temp.erase(temp.begin()+i);
		q=max(q,nums[i]*left*right+dp(temp));
	}
	return q;
}
int maxCoins(vector<int>& nums) {
    return dp(nums);
}
//
vector<vector<int>> memo;
int dp(vector<int>& nums,int left, int right)
{
	if(left<0||right>=nums.size()||left>right)
		return 0;
	if(memo[left][right]!=-1)
		return memo[left][right];
	int q=INT_MIN;
	for(int i=left;i<=right;++i)
	{
		int lval=left-1<0?1:nums[left-1];
		int rval=right+1>=nums.size()?1:nums[right+1];
		q=max(q,nums[i]*lval*rval+dp(nums,left,i-1)+dp(nums,i+1,right));
	}
	return memo[left][right]=q;
}
int maxCoins(vector<int>& nums)
{
	memo.resize(nums.size(),vector<int>(nums.size(),-1));
	return dp(nums,0,nums.size()-1);
}
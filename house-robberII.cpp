int dp(int index,vector<int>& nums,bool flag)
{
	if(index>=nums.size())
		return 0;
	else if(index==nums.size()-1&&flag)
		return 0;
	if(memo[index][flag]!=-1)
		return memo[index][flag];
	int not_taken=dp(index+1,nums,flag);
	if(index==0)
		flag=true;
	int taken=nums[index]+dp(index+1,nums,flag);
	return memo[index][flag]=max(taken,not_taken);
}
int rob(vector<int>& nums) 
{
    return dp(0,nums,false);
}
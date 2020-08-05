int longestSubarray(vector<int>& nums) 
{
	int n=nums.size();
	int slow=0,fast=0,zc=0,len=0;
	while(fast<n)
	{
		if(nums[fast]==0)
			++zc;
		++fast;
		while(zc==2)
		{
			if(nums[slow]==0)
				--zc;
			++slow;
		}
		len=max(len,fast-slow);
	}
	return len-1;    
}
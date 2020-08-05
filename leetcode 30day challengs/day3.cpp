int maxSubArray(vector<int>& nums)
{
	int maxSum=nums[0],currSum=0,head=0,tail=0;
	for(int i=0;i<nums.size();++i)
	{
		currSum+=nums[i];
		if(currSum>maxSum)
			maxSum=currSum;
		if(currSum<0)
			currSum=0;
	}  
	return maxSum;      
}
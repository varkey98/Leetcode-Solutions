bool binarySearch(int start,int end,vector<int>& arr,int val)
{
	int q;
	while(start<=end)
	{
		q=start+(end-start)/2;
		if(arr[q]==val)
			return true;
		else if(val<arr[q])
			end=q-1;
		else start=q+1;

	}
	return false;
}
int findDuplicate(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	for(int i=0;i<nums.size()-1;++i)
		if(binarySearch(i+1,nums.size()-1,nums,nums[i]))
			return nums[i];
	return 0;
}
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	int i=0,j=0;
	int smallest;
	while(i!=nums1.size()&&j!=nums2.size())
	{
		if(nums1[i]<nums2[j])
		{
			smallest=nums[i];
			++i;
		}
		else
		{
			smallest=nums2[j];
			++j;
		}
	}
}

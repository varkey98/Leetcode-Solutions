#define mod 1000000007
int numOfSubarrays(vector<int>& arr) 
{
	int slow=0,fast=0,n=arr.size(),sum=0;
	long ret=0;
	while(fast<n)
	{
		sum+=arr[fast];
		if(sum%2==1)
			++ret;
		else
			while(sum>0&&sum%2==0)
			{
				sum-=arr[slow];
				++slow;
			}
		++fast;
	}
	return ret%mod;
}
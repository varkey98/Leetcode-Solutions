int fun(vector<int>& a,int k)
{
    if(k<=0)
        return 0;
	int slow=0,fast=0,c=0;
	map<int,int> arr;
	int ret=0;
	while(fast<a.size())
	{
		while(c<=k&&fast<a.size())
        {
            if(arr.find(a[fast])==arr.end()||arr[a[fast]]==0)
                ++c;
			arr[a[fast]]++;
            ++fast;
        }
		if(c==k+1)
		{
            fast--;
			arr[a[fast]]--;
            --c;
			while(c==k)
			{
				ret+=fast-slow;
				arr[a[slow]]--;
				if(arr[a[slow]]==0)
					--c;
				++slow;
			}
		}		
	}
	while(slow<a.size())
    {
		ret+=fast-slow;
        ++slow;
    }
	return ret;
}
int subarraysWithKDistinct(vector<int>& arr, int k) 
{
	return fun(arr,k)-fun(arr,k-1);
}
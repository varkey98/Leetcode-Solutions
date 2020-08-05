int minSumOfLengths(vector<int>& arr, int target) 
{
    priority_queue<int,vector<int>,greater<int>> q;
    int slow=0,fast=-1,sum=0;
    while(slow<arr.size())
    {
    	if(sum==target)
    	{
            cout<<fast-slow+1<<endl;
    		q.push(fast-slow+1);
            sum=0;
    		slow=fast+1;
    	}
    	else if(sum<target)
    	{
    		++fast;
    		if(fast<arr.size())
    			sum+=arr[fast];
    		else break;
    	}
    	else
    	{
            while(sum>target)
            {
    		sum-=arr[slow];
    		++slow;
            }
    	}

    }
    if(q.size()<2)
    	return -1;
    else
    {
    	int ret=q.top();
    	q.pop();
    	return ret+q.top();
    }
}

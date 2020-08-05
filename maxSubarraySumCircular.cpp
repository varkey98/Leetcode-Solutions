int maxSubarraySumCircular(vector<int>& A) 
{
	int ret=INT_MIN;
    for(int i=0;i<A.size();++i)
    {
    	int maxSum=INT_MIN;
    	int currsum=0;
    	for(int j=i;;)
    	{
    		currsum+=A[j];
    		maxSum=max(maxSum,currsum);
    		if(currsum<0)
    			currsum=0;
    		j=(j+1)%A.size();
    		if(j==i)
    			break;
    	}
    	ret=max(ret,maxSum);
    }
    return ret;
}
int maxSubarraySumCircular(vector<int>& A) 
{
	int maxSum=INT_MIN;
	int minSum=INT_MAX;
	int currsum=0,val=0,t=0;
	for(int j=0;j<A.size();++j)
	{
		currsum+=A[j];
		maxSum=max(maxSum,currsum);
		if(currsum<0)
			currsum=0;
		val+=A[j];
		minSum=min(minSum,val);
		if(val>0)
			val=0;
		t+=A[j];
	}
    return minSum==t?maxSum:t-minSum;
}
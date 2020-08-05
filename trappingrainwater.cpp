//brute force algorithm, TLE
int fun(int level,vector<int>& height)
{
	int ret=0;
	int start=-1;
	for(int i=0;i<height.size();++i)
		if(height[i]>level)
		{
			if(start==-1)
				start=i;
			else
				ret+=i-start-1;
			start=i;
		}

	return ret;

}
int trap(vector<int>& height) 
{
    int ret=0;
    cout<<height.size();
    if(height.size()>2)
    {
        int h=*max_element(height.begin(),height.end());
        for(int i=0;i<h;++i)
            ret+=fun(i,height);
    }
    return ret;
}
//accepted, O(n^2)
int trap(vector<int>& height) 
{
	int ret=0;
	for(int i=0;i<height.size();++i)
	{
		int elevation=0;
		for(int after=i+1;after<height.size();++after)
			if(height[after]>elevation)
			{
				ret+=(after-i-1)*(min(height[i],height[after])-elevation);
				elevation=min(height[i],height[after]);
			}
	}
	return ret;
}
// dynamic programming
vector<int> leftmax;
vector<int> rightmax;
void dp(vector<int>& height)
{
	leftmax.resize(height.size(),0);
	rightmax.resize(height.size(),0);
	for(int i=height.size()-2;i>=0;--i)
		rightmax[i]=max(height[i+1],rightmax[i+1]);
	for(int i=1;i<height.size();++i)
		leftmax[i]=max(height[i-1],leftmax[i-1]);
}
int trap(vector<int>& height)
{
    if(height.size()<3)
        return 0;
	int ret=0;
    dp(height);
	for(int i=0;i<height.size();++i)
	{
		int val=min(leftmax[i],rightmax[i])-height[i];
        if(val>0)
            ret+=val;
	}
    cout<<leftmax[1]<<rightmax[1];
	return ret;
}
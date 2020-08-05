void merge(vector<int>& nums,int p,int q,int r)
{
	int sp=q+1;
	int c=0;
	int i;
	for(i=p;i<=q;++i)
	{
		if(!nums[i])
		{
			if(sp>r)
				break;
			else
			{
				nums[i]=nums[sp];
				++c;
				++sp;
			}
		}
	}
if(sp<=r)
{
	while(sp<=r)
	{
		nums[i]=nums[sp];
		++i;
		++sp;
	}
	while(c)
	{
		nums[i]=0;
		++i;
		--c;
	}
}
else
	for(;i<=r;++i)
		nums[i]=0;
}
void reArrange(vector<int>& nums,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		reArrange(nums,p,q);
		reArrange(nums,q+1,r);
		merge(nums,p,q,r);
	}
}

void moveZeroes(vector<int>& nums)
{
	reArrange(nums,0,nums.size()-1);

}

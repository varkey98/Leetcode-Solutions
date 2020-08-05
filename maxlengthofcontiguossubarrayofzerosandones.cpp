int findMaxLength(vector<int>& nums) 
{
	map<int,int> pi;
	int count=0,i=0,ret=0;
	for(int x:nums)
	{
		count+=x==1?1:-1;
		if(m.find(count)!=m.end())
			ret=max(ret,i-pi[count]);
		else pi[count]=1
		++i;
	}       
	return ret;
}
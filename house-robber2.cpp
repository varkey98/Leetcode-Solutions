map<int,int> mp;
int traverse(vector<int> v,int start,bool* flag)
{
	if(start<v.size())
	{
		if(mp.count(start))return mp[start];
		int ret=v[start];
		ret+=traverse(v,start+2);
		mp[start]= max(ret,traverse(v,start+1));
		if(start==v.size()-1)
		{
			mp[start]=max(ret,v[0]);
			
		}
		return mp[start];
	}
	else return 0;
}
int rob(vector<int>& nums)
{
	bool flag=false;
    int n=traverse(nums,1,&flag); 
    if(!flag)
    	n+=
}
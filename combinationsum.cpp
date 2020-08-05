vector<vector<int>> ret;
void dp(int val,vector<int>& c,int target,vector<int> v,int index)//no memo!,plain backtracking
{
	if(val==target)
		ret.push_back(v);
	else if(val<target)
		for(int i=index;i<c.size()&&val+c[i]<=target;++i)
		{
			int x=c[i];
			v.push_back(x);
			dp(val+x,c,target,v,i);
			v.pop_back();
		}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(),candidates.end());
	dp(0,candidates,target,{},0);
	return ret;    
}

vector<int> topKFrequent(vector<int>& nums,int k)
{
	map<int,int> m;
	for(int i=0;i<nums.size();++i)
		m[nums[i]]+=1;
	typedef pair<int,int> val;
	priority_queue<val> q;
	map<int,int>::iterator itr= m.begin();
	while(itr!=m.end())
	{
		q.push(make_pair(itr->second,itr->first));
        ++itr;
	}
	vector<int> ret;
	while(k--)
	{
		ret.push_back(q.top().second);
		q.pop();
	}
return ret;
}
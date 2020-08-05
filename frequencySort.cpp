string frequencySort(string s) 
{
	map<char,int> m;
	for(int i=0;i<s.length();++i)
		m[s.at(i)]+=1;
	typedef pair<int,char> val;
	priority_queue <val> q;
	map<char,int>::iterator itr=m.begin();
	while(itr!=m.end())
	{
		q.push(make_pair(itr->second,itr->first));
		++itr;
	}
	string ret;
	int n;
	while(!q.empty())
	{
		n=q.top().first;
		while(n--)
			ret.push_back(q.top().second);
		q.pop();
	}
	return ret;
}
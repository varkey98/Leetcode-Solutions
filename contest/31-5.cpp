int minReorder(int n, vector<vector<int>>& c) 
{
	queue<int> q;
	vector<int> memo(n,0);
	q.push(0);
	int ret=0;
	memo[0]=1;
	vector<vector<int>> out(n,vector<int>(0,0));
	vector<vector<int>> in(n,vector<int>(0,0));
	for(auto v:c)
	{
		out[v[0]].push_back(v[1]);
		in[v[1]].push_back(v[0]);
		if(v[1]==0)
		{
			q.push(v[0]);
			memo[v[0]]=1;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto v:out[u])
			if(!memo[v])
			{
				++ret;
				memo[v]=1;
				q.push(v);
			}
		for(auto v:in[u])
		{
			memo[v]=1;
			q.push(v);
		}

	}
	return ret;
}
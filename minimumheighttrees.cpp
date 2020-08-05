int bfs(vector<vector<int>>& e,int v,int n)
{
	int* d=(int*)calloc(n,sizeof(int));
	int* g=(int*)calloc(n,sizeof(int));
	d[v]=0;
	queue<int> q;
	q.push(v);
	g[v]=1;
	int max=0;
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		for(int x:e[v])
			if(g[x]==0)
			{
				d[x]=d[v]+1;
				q.push(x);
				g[x]=1;
				if(d[x]>max)
					max=d[x];
			}
	}
	return max;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{
	vector<vector<int>> e(n,vector<int>(0,0));
	for(int i=0;i<edges.size();++i)
	{
		e[edges[i][0]].push_back(edges[i][1]);
		e[edges[i][1]].push_back(edges[i][0]);
	}
	vector<int> ret;
	int h=INT_MAX;
	for(int i=0;i<n;++i)
	{
		int val=bfs(e,i,n);
		if(val<h)
		{
			ret.clear();
			ret.push_back(i);
			h=val;
		}
		else if(val==h)
			ret.push_back(i);
	}
	return ret;	    
}
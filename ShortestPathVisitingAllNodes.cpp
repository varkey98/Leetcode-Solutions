void warshall(vector<vector<int>>& dist,vector<vector<int>>& graph)
{
	int n=graph.size();
	for(int i=0;i<n;++i)
		for(int v:graph[i])
			dist[i][v]=1;
	for(int k=0;k<n;++k)
		for(int u=0;u<n;++u)
			for(int v=u+1;v<n;++v)
				dist[u][v]=dist[v][u]=min(dist[u][v],dist[u][k]+dist[k][v]);
}
vector<vector<int>> memo;
int dp(int mask,int v,vector<vector<int>>& dist,int allmask)
{
	if(mask==allmask)
		return 0;
	if(v>=dist.size())
		return 25;
	if(memo[mask][v]!=-1)
		return memo[mask][v];
	int n=dist.size();
	int q=25;
	for(int i=0;i<n;++i)
		if(i==v||mask&(1<<i))
            continue;
        else
			q=min(q,dist[v][i]+dp(mask|(1<<i),i,dist,allmask));
	return memo[mask][v]=q;
}
int shortestPathLength(vector<vector<int>>& graph) {
    vector<vector<int>> dist(graph.size(),vector<int>(graph.size(),25));
    warshall(dist,graph);
    int allmask=(1<<graph.size())-1;
    memo.resize(allmask,vector<int>(graph.size(),-1));
    int q=25;
    for(int i=0;i<graph.size();++i)
        q=min(q,dp(1<<i,i,dist,allmask));
    cout<<dist.size()<<graph.size();
    return q;
    return 0;
}
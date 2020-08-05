vector<int> memo;
vector<int> in;
vector<int> out;
int dp(int u,vector<vector<int>>& e)
{
	if(memo[u]!=-1)
		return memo[u];
	int q=1;
	for(int v:e[u])
		q+=dp(v,e,);
	return memo[u]=q;
}
int dp_in(int u,vector<vector<int>>& e)
{
	if(in[u]!=-1)
		return in[u];
	int q=0;
	for(int v:e[u])
		q+=memo[v]+dp_in(v,e);
	return in[u]=q;
}
int dp_out(int u,int parent)
vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
{
    memo.resize(N,-1);
    in.resize(N,-1);
    level.resize(N,-1);
    vector<vector<int>> e(N,vector<int>(0,0));
    for(int i=0;i<edges.size();++i)
    	e[edges[i][0]].push_back(edges[i][1]);
    dp(0,e,0);
    dp_dfs(0,e);
    int totaldist=in[0];
    vector<int> ret;
    for(int i=0;i<N;++i)
    {
    	//int val=totaldist-in[i]+N-memo[i]+in[i];
    	int val=totaldist+N-memo[i];
    	ret.push_back(val);
    }
    return ret;
}
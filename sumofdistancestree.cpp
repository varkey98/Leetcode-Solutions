vector<int> memo;
vector<int> out;
vector<int> ret;
int root;
int dp(int u,vector<vector<int>>& adj,int parent)
{
	if(memo[u]!=-1)
		return memo[u];
	else 
	{
		int q=1;
		for(int v:adj[u])
            if(v!=parent)
            {
                q+=dp(v,adj,u);
                out[u]+=out[v];
            }
		out[u]+=q-1;
		return memo[u]=q;
	}
}
void dfs(int u,vector<vector<int>>& adj,int parent)
{
	if(u==0)
		ret[u]=out[u];
	else
		ret[u]=adj.size()+ret[parent]-2*memo[u];
    for(int v:adj[u])
        if(v!=parent)
            dfs(v,adj,u);
}
vector<int> sumOfDistancesInTree(int N,vector<vector<int>>& edges)
{
	vector<vector<int>> adj(N);
	vector<int> parent(N,-1);
	for(auto x:edges)
	{
		adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
	}
	memo.resize(N,-1);
	out.resize(N,0);
	ret.resize(N);
	dp(0,adj,-1);
	dfs(0,adj,-1);
	return ret;
}
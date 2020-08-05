// DFS solution
bool ret=true;
vector<int> color;
void dfs(int v,vector<vector<int>>& adj)
{
	color[v]=0;
	for(int u:adj[v])
		if(color[u]==1)
			dfs(u,adj);
		else if(color[u]==0)
			ret=false;
	color[v]=-1;
}
bool canFinish(int n, vector<vector<int>>& prereq) 
{
	vector<vector<int>> adj(n,vector<int>(0,0));
	color.resize(n,1);
	for(auto v:prereq)
		adj[v[1]].push_back(v[0]); 
	for(int i=0;i<n;++i)
		if(color[i]==1)
			dfs(i,adj);
	return ret; 

}
//incomplete
void bfs(int n,vector,vector<int>>& adj)
{
	vector<int> visited(n,0);
	queue<int> q;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		visited[u]=1;
		for(int v:adj[u])
			if(visited[v]!=1)
				q.push(v);
			else ret=false;
	}
}
bool canFinish(int n, vector<vector<int>>& prereq) 
{
	vector<vector<int>> adj(n,vector<int>(0,0));
	color.resize(n,1);
	for(auto v:prereq)
		adj[v[1]].push_back(v[0]); 
	for(int i=0;i<n;++i)
		if(color[i]==1)
			dfs(i,adj);
	return ret; 

}

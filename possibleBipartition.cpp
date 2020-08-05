bool possibleBipartition(int N, vector<vector<int>>& dislikes) //1 is white,0 is grey,-1 is black
{
	vector<int> visited(N+1,1);
	vector<vector<int>> adj(N+1,vector<int>(0,0));
	queue<int> q;
	for(auto v:dislikes)
	{
		adj[v[0]].push_back(v[1]);   
		adj[v[1]].push_back(v[0]); 
	}
	vector<int> color(N+1,-1);
    for(int i=1;i<=N;++i)// this loop is to make sure is that every person is checked.
        if(visited[i]==1)
        {
			visited[i]=0;
			q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				vector<int> c(N+1,0);
				for(int v:adj[u])
					if(visited[v]==1)
					{
						q.push(v);
						visited[v]=0;
					}
					else if(visited[v]==-1)
						c[color[v]]=1;
				for(int i=1;i<c.size();++i)
		        {
					if(i>2)
						return false;
					if(c[i]==0)
					{
						color[u]=i;
		                break;
					}
		        }
				visited[u]=-1;
			}
        }
	return true;
}
int dfs(int u,vector<int>& pi,vector<int>& visited)
{
    if(visited[u]==-1)
    {
        visited[u]=1;
        if(pi[u]==-1)
            return 0;
        else return 2+dfs(pi[u],pi,visited);
    }
    else return 0;
}
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> e (n,vector<int>(0,0));
    for(auto v:edges)
    {
        e[v[0]].push_back(v[1]);
    }
    queue<int> q;
    q.push(0);
    vector<int> pi(n,-1);
    vector<int> req;
    while(!q.empty())
    {
        int v=q.front();
        if(hasApple[v])
            req.push_back(v);
        q.pop();
        for(int u:e[v])
        {
            pi[u]=v;
            q.push(u);
        }
    }
    vector<int> visited(n,-1);
    int ret=0;
    for(int u:req)
        ret+=dfs(u,pi,visited);
    //cout<<pi[5]<<" "<<pi[2];
    return ret;
}
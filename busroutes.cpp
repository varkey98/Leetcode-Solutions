int numBusesToDestination(vector<vector<int>>& routes, int s, int t) 
{
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<routes.size();++i)
    	for(int x:routes[i])
    		if(adj.find(x)==adj.end())
    			adj[x]={i};
    		else adj[x].push_back(i);
    unordered_set<int> grey;
    unordered_set<int> grey_routes;
    queue<pair<int,int>> q;
    q.push({s,0});
    grey.insert(s);
    while(!q.empty())
    {
    	auto temp=q.front();
        q.pop();
    	s=temp.first;
    	int ret=temp.second;
    	if(s==t)
    		return ret;
    	else
    		for(int r:adj[s])
    			if(grey_routes.find(r)==grey_routes.end())
    			{
    				for(int v:routes[r])
    					if(grey.find(v)==grey.end())
    					{
    						q.push({v,ret+1});
    						grey.insert(v);
    					}
    				grey_routes.insert(r);
    			}
    }

    return -1;
}
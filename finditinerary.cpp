vector<string> ret;
bool flag=true;
void dfs(string i,unordered_map<string,map<string,int>>& adj,vector<string> v,int n)
{
	v.push_back(i);
	if(v.size()==n+1&&flag)
	{
		flag=false;
		ret=v;
	}		
	else
		for(auto  itr=adj[i].begin();itr!=adj[i].end();++itr)
			if(itr->second>0)
			{
				itr->second--;
				dfs(itr->first,adj,v,n);
                itr->second++;
				if(!flag)
					break;
			}
}
vector<string> findItinerary(vector<vector<string>>& tickets) 
{
	unordered_map<string,map<string,int>> adj;
	for(auto u:tickets)
	{
		if(adj.find(u[0])!=adj.end())
			adj[u[0]][u[1]]++;
		else
		{
			map<string,int> temp;
			temp[u[1]]=1;
			adj[u[0]]=temp;
		}
	}
	dfs("JFK",adj,{},tickets.size());
	return ret;
}
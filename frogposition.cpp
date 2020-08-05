struct node
{
	int val;
	int time;
	double prob;
};
node* createNode()
{
	node* ret=(node*)malloc(sizeof(node));
	ret->val=0;
	ret->time=0;
	ret->prob=0;
	return ret;
}
double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
{
    vector<vector<int>> adj(n+1);
    vector<int> grey(n+1,0);
    for(auto v:edges)
    {
    	adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    node* u=createNode();
    u->val=1;
    u->prob=1;
    grey[1]=1;
    queue<node*> q;
    q.push(u);
    while(!q.empty())
    {
    	u=q.front();
    	q.pop();
    	int flag=0;
    	if(t==u->time&&u->val==target)
    		return u->prob;
    	else 
    	{
    		for(int v:adj[u->val])
    			if(!grey[v])
    				++flag;
    		if(flag)
				for(int v:adj[u->val])
					if(!grey[v])
					{
						grey[v]=1;
						node* temp=createNode();
						temp->val=v;
						temp->time=u->time+1;
						temp->prob=u->prob*(1.0/flag);
						q.push(temp);
					}
			if(t>u->time&&u->val==target&&flag==0)
				return u->prob;    	
		}
    }
    return 0;

}
int find(int* parent,int x)
{
	if(parent[x]==-1)
		return x;
	else return find(parent,parent[x]);
}
int uni(int* parent,int x,int y)
{
	int xp=find(parent,x);
	int yp=find(parent,y);
	if(xp!=yp)
	{
		parent[xp]=yp;
		return 1;
	}
	else return 0;
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
{
        
}
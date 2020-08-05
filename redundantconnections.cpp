//UNION-FIND-ALGORITHM
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
vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
	int n=edges.size();
	int* parent=(int*)calloc(n+1,sizeof(int));
	for(int i=0;i<=n;++i)
		parent[i]=-1;
	int i;
	for(i=0;i<n;++i)
		if(!uni(parent,edges[i][0],edges[i][1]))
			break; 
	return edges[i];       
}
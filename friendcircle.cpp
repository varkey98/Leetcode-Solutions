vectpr<int> parent;
int find(int x)
{
	if(parent[x]!=-1)
		return find(parent[x]);
	else return x;
}
bool uni(int x,int y)
{
	int xp=find(x);
	int yp=find(y);
	if(xp!=yp)
	{
		parent[yp]=xp;
		return true;
	}
	return false;
}
int findCircleNum(vector<vector<int>>& M) 
{
	int n=M.size();
	int ret=n;
	parent.resize(n,-1);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(M[i][j])
				if(uni(i,j))
					--ret;

	return ret;
}
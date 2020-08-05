vector<int> p;
int size;
vector<vector<int>> memo;
TreeAncestor(int n, vector<int>& parent) 
{
    p=parent;
    size=n;
    memo.resize(n,vector<int>(log2(n)+1,-5));
    for(int i=0;i<n;++i)
        memo[i][0]=parent[i];
    for(int j=1;j<=log2(n);++j)
        for(int i=0;i<n;++i)
            memo[i][j]=memo[i][j-1]!=-1?memo[memo[i][j-1]][j-1]:-1;
}

int getKthAncestor(int node, int k) 
{
	if(k>=size)
		return -1;
	if(!k||node==-1)
		return node;
    int val=log2(k);
    int ret=pow(2,val);
    return ret==k?memo[node][val]:getKthAncestor(memo[node][val],k-ret);
}
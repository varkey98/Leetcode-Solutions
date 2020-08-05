vector<vector<int>> memo;
bool dp(int x,int y,vector<vector<int>>& adj)
{
	if(memo[x][y]!=-1)
		return memo[x][y];
	int q=0;
	if(x==y)
		return memo[x][y]=1;
    for(int u:adj[x])
    {
        q+=dp(u,y,adj);
        if(q)
            break;
    }
	if(q)
		return memo[x][y]=1;
	else return memo[x][y]=0;
}
vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& q) 
{
	memo.resize(n,vector<int>(n,-1));
	vector<vector<int>> adj(n,vector<int>(0,0));
	for(auto v:prereq)
		adj[v[0]].push_back(v[1]);
	vector<bool> ret;
	for(auto v:q)
		if(dp(v[0],v[1],adj))
			ret.push_back(true);
		else ret.push_back(false);
	return ret;
}

bool hasAllCodes(string s, int k) 
{
	unordered_set<int> st;
	string t;
	for(int i=0;i<k;++i) 
		t.push_back(s[i]);
	st.insert(t);
	for(int i=k;i<s.length();++i)
	{
		string temp=t.substr(1);
		temp+=s[i];
		st.insert(temp);
	}
	if(st.size()==pow(2,k))
		return true;
	else return false;   
}	
vector<vector<int>> memo;
int dp(int i,int r1,int r2,vector<vector<int>>& grid)
{
	if(r1<0||r2<0||r1>=grid[0].size()||r2>=grid[0].size()||i>=grid.size())
		return 0;
	if(memo[r1][r2]!=-1)
		return memo[r1][r2];
	int q=0;
	if(abs(r1-r2)>2)
		for(int j=-1,k=-1;j<=1,k<=1;++j,++k)
			q=max(q,dp(i+1,r1+j,r2+k,grid));
	else if(abs(r1-r2)==2)
	{
		for(int j=-1,k=1;j<=0,k>=0;++j,--k)
			q=max(q,dp(i+1,r1+j,r2+k,grid));
		for(int j=0;j<=1;++j)
			q=max(q,dp(i+1,r1+1,r2+j,grid));
		for(int j=-1;j>=0;++j)
			q=max(q,dp(i+1,r1+j,r2-1,grid));
	}
	else
	{
		for(int k=-1;k<=1;++k)
			q=max(q,dp(i+1,r1-1,r2+k,grid));
		for(int j=-1;j<=1;++j)
			q=max(q,dp(i+1,r1+j,r2+1,grid));
	}
	return memo[r1][r2]=q;

}
int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size();
    if(n)
    {
    	int m=grid[0].size();
    	memo.resize(m,vector<int>(m,-1));
    	if(m)
    		return dp(0,0,m-1,grid);
    }
    return 0;
}
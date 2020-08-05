vector<vector<bool>> memo;
vector<int> r;
int dfs(int i,string& s)
{
    if(i>=s.length())//because even after finding the last partition, it'll perform a cut marking the end of the string, which is unnecessary.
        return -1;
    else if(r[i]!=-1)
        return r[i];
	else
	{
		int q=s.length();
		for(int j=i;j<s.length();++j)
			if(memo[i][j])
				q=min(q,1+dfs(j+1,s));
		return r[i]=q;
	}
}
int minCut(string s) 
{
	int n=s.size();
	memo.resize(n,vector<bool>(n,false));
    r.resize(n,-1);
	for(int l = 1; l <=n; l++)
		for(int i = 0; i < n; i++)
		{
			int j = i + l - 1;
			if(j >= n) break;
			memo[i][j] = (i + 1 > j - 1 || memo[i + 1][j - 1]) && s[i] == s[j];
		}
    return dfs(0,s);
    
}
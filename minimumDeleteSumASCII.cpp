vector<vector<int>> memo;
int dp(string& s,string& t,int i,int j)
{
	if(i>=s.length()&&j>=t.length())
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
    if(i>=s.length())
        return memo[i][j]=t[j]+dp(s,t,i,j+1);
    if(j>=t.length())
        return memo[i][j]=s[i]+dp(s,t,i+1,j);    
	int q=0;
	if(s[i]==t[j])
		q=dp(s,t,i+1,j+1);
	else
		q=min(s[i]+dp(s,t,i+1,j),t[j]+dp(s,t,i,j+1));
	return memo[i][j]=q;
}
int minimumDeleteSum(string s1, string s2) 
{
    memo.resize(s1.length()+1,vector<int>(s2.length()+1,-1));
    return dp(s1,s2,0,0);
}
vector<vector<int>> memo;
int dp(string& s,string& t,int i,int j)
{
	if(i>=s.length()&&j>=t.length())
		return 0;
	if(j>=t.length())
		return s.length()-i;
    if(i>=s.length())
        return t.length()-j;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int q;
	if(s[i]==t[j])
		q=dp(s,t,i+1,j+1);
	else
	{
		int in=1+dp(s,t,i,j+1);//insert
		int del=1+dp(s,t,i+1,j);//delete
		int re=1+dp(s,t,i+1,j+1);//replace
		q=min(in,del);
		q=min(q,re);
	}
	return memo[i][j]=q;
}
int minDistance(string word1, string word2) 
{
    memo.resize(word1.length(),vector<int>(word2.length(),-1));
    return dp(word1,word2,0,0);
}
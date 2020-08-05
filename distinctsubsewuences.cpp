vector<vector<int>> memo;
int dp(int i,int j,string& s,string& t)
{
    if(j>=t.length())
        return 1;
    else if(i>=s.length())
        return 0;
    else if(memo[i][j]!=-1)
        return memo[i][j];
    else
    {
        int q=0;
        if(s[i]==t[j])
            q+=dp(i+1,j+1,s,t);
        q+=dp(i+1,j,s,t);
        return memo[i][j]=q;
    }
}
int numDistinct(string s, string t) 
{
    memo.resize(s.length(),vector<int>(t.length(),-1));
    return dp(0,0,s,t);
}
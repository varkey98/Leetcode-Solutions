vector<vector<int>> memo;
string ret;
int dp(int i,int j,string& a,string& b)
{
    if(i==a.length()&&j==b.length())
        return 0;
    else if(i==a.length())
        return b.length()-j;
    else if(j==b.length())
        return a.length()-i;
    else if(memo[i][j]!=-1)
        return memo[i][j];
    else
    {
        int q;
        if(a[i]==b[j])
            q=1+dp(i+1,j+1,a,b);
        else
            q=min(1+dp(i+1,j,a,b),1+dp(i,j+1,a,b));
        return memo[i][j]=q;
    }
}
void dfs(int i,int j,string& a,string& b)
{
    if(i==a.length()&&j==b.length())
        return;
    else if(i==a.length())
        while(j!=b.length())
            ret.push_back(b[j++]);
    else if(j==b.length())
        while(i!=a.length())
            ret.push_back(a[i++]);
    else
    {
        if(a[i]==b[j])
        {
            ret.push_back(a[i]);
            dfs(i+1,j+1,a,b);
        }
        else
            if(1+dp(i+1,j,a,b)==memo[i][j])
            {
                ret.push_back(a[i]);
                dfs(i+1,j,a,b);
            }
            else
            {
                ret.push_back(b[j]);
                dfs(i,j+1,a,b);
            }            
    }
}
string shortestCommonSupersequence(string str1, string str2) 
{
    memo.resize(str1.length(),vector<int>(str2.length(),-1));
    cout<<dp(0,0,str1,str2)<<endl;
    dfs(0,0,str1,str2);
    return ret;
}
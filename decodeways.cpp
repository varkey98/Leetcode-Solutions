vector<int> memo;
vector<int> used_zero;
int dp(int i,string s)
{
    if(i>=s.length())
        return 1;
    else if(memo[i]!=-1)
        return memo[i];
    else
    {
        int q=0;
        int j=s[i]-'0';
        if(j!=0)
            q=dp(i+1,s);
        else return 0;
        if(i+1<s.length())
        {
            j=j*10+s[i+1]-'0';
            if(j>=1&&j<=26)
            {
                used_zero[i+1]=1;
                q+=dp(i+2,s);    
            }
        }
        return memo[i]=q;
    }
}
int numDecodings(string s) 
{
    memo.resize(s.length(),-1);
    used_zero.resize(s.length(),0);
    int val= dp(0,s);
    for(int i=0;i<s.length();++i)
        if(s[i]=='0'&&used_zero[i]==0)
            return 0;
    return val;
}
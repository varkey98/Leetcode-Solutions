vector<int> memo;
vector<int> zero_taken;
long dp(int i,string& s)
{
    if(i>=s.length())
        return 1;
    else if(memo[i]!=-1)
        return memo[i];
    else
    {
        int j=0,flag=0;
        long q=0;
        if(s[i]=='*')
        {
            q=9*dp(i+1,s);
            flag=1;
        }
        else if(s[i]=='0')
            return 0;
        else
        {
            j=s[i]-'0';
            q=dp(i+1,s);
        }
        if(i+1<s.length())
        {
            if(s[i+1]=='*')
            {
                if(flag)
                    q+=15*dp(i+2,s);
                else if(j==1)
                    q+=9*dp(i+2,s);
                else if(j==2)
                    q+=6*dp(i+2,s);
            }
            else
            {
                if(flag)
                {
                    if(s[i+1]>='1'&&s[i+1]<='6')
                        q+=2*dp(i+2,s);
                    else if(s[i+1]>'6')
                        q+=dp(i+2,s);
                    else if(s[i+1]=='0')
                    {
                        q+=2*dp(i+2,s);
                        zero_taken[i+1]=1;
                    }
                }
                else
                {
                    j=j*10+s[i+1]-'0';
                    if(j<=26)
                    {
                        if(s[i+1]=='0')
                            zero_taken[i+1]=1;
                        q+=dp(i+2,s);
                    }
                }
            }
        }
        return memo[i]=q%mod;
    }
}
int numDecodings(string s) 
{
    int n=s.length();
    memo.resize(n,-1);
    zero_taken.resize(n,0);
    int val=dp(0,s);
    for(int i=0;i<n;++i)
        if(s[i]=='0'&&zero_taken[i]==0)
            return 0;
    return val;
}
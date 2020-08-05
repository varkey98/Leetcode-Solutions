vector<vector<int>> memo;
bool dp(int i,vector<int>& s,int k)
{
    if(i>=s.size()-1)
        return true;
    if(memo[i][k]!=-1)
        return memo[i][k];
    int a=i,b=i,c=i;
    for(int j=i+1;j<s.size();++j)
    {
        if(s[j]>s[i]+k+1)
            break;
        else if(s[j]==s[i]+k-1)
            a=j;
        else if(s[j]==s[i]+k)
            b=j;
        else if(s[j]==s[i]+k+1)
            c=j;
    }
    bool q=false;
    if(a!=i)
        q=q||dp(a,s,k-1);
    if(b!=i)
        q=q||dp(b,s,k);
    if(c!=i)
        q=q||dp(c,s,k+1);
    return memo[i][k]=q;
}
bool canCross(vector<int>& stones) {
    memo.resize(stones.size(),vector<int>(stones.size(),-1));
    if(stones.size()>1)
        if(stones[1]>1)
            return false;
    return dp(1,stones,1);
}
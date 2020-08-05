int [][][] memo;
int dp(int i,int k,int[] p,boolean flag)
{
    if(k==0&&flag==false)
        return 0;
    else if(i>=p.length&&flag)
        return -10000;
    else if(i>=p.length)
        return 0;
    boolean t=false;
    if(memo[i][k][flag?1:0]>0)
        return memo[i][k][flag?1:0];
    else
    {
        int q=dp(i+1,k,p,flag);
        if(flag)
            q=Math.max(q,dp(i+1,k,p,false)+p[i]);
        else
            q=Math.max(q,dp(i+1,k-1,p,true)-p[i]);
        return memo[i][k][flag?1:0]=q;
    }
}
int greedy(int[] p)
{
    int ret=0;
    for(int i=1;i<p.length;++i)
        ret+=p[i]>p[i-1]?p[i]-p[i-1]:0;
    return ret;
}
public int maxProfit(int k, int[] prices) 
{
    if(k>=prices.length/2)
        return greedy(prices);
    else
    {
        memo=new int[prices.length][k+1][2];
        return dp(0,k,prices,false);
    }
}


vector<vector<vector<int>>> memo;
int dp(int i,int k,vector<int>& p,bool flag)
{
    if(k==0&&flag==false)
        return 0;
    else if(i>=p.size()&&flag)
        return -10000;
    else if(i>=p.size())
        return 0;
    if(memo[i][k][flag?1:0]>0)
        return memo[i][k][flag?1:0];
    else
    {
        int q=dp(i+1,k,p,flag);
        if(flag)
            q=max(q,dp(i+1,k,p,false)+p[i]);
        else
            q=max(q,dp(i+1,k-1,p,true)-p[i]);
        return memo[i][k][flag?1:0]=q;
    }
}
int greedy(vector<int>& p)
{
    int ret=0;
    for(int i=1;i<p.size();++i)
        ret+=p[i]>p[i-1]?p[i]-p[i-1]:0;
    return ret;
}

int maxProfit(int k,vector<int>& prices) 
{
    if(k>=prices.size()/2)
        return greedy(prices);
    memo.resize(prices.size(),vector<vector<int>>(k+1,vector<int>(2)));
    return dp(0,k,prices,false);
}
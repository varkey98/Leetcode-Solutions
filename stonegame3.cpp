Integer[][] memo;//O(N) DP Accepted
int dp(int i,int p,int[] stones)
{
    if(i>=stones.length)
        return 0;
    else if(memo[i][p]!=null)
        return memo[i][p];
    else
    {
        int g1=Integer.MAX_VALUE,g2=Integer.MAX_VALUE,g3=Integer.MAX_VALUE;
        int val=stones[i];
        g1=dp(i+1,(p+1)%2,stones)+(p==0?val:-val);
        if(i+1<stones.length)
        {
            val+=stones[i+1];
            g2=dp(i+2,(p+1)%2,stones)+(p==0?val:-val);
        }
        if(i+2<stones.length)
        {
            val+=stones[i+2];
            g3=dp(i+3,(p+1)%2,stones)+(p==0?val:-val);
        }
        int ret=g1;
        if(g2!=Integer.MAX_VALUE)
            ret=p==0?Math.max(ret,g2):Math.min(ret,g2);
        if(g3!=Integer.MAX_VALUE)
            ret=p==0?Math.max(ret,g3):Math.min(ret,g3);
        return memo[i][p]=ret;
            
    }  
}
public String stoneGameIII(int[] stoneValue) 
{
    memo=new Integer[stoneValue.length][2];
    /*for(int[] temp:memo)
        Arrays.fill(temp,Integer.MAX_VALUE);*/
    int val=dp(0,0,stoneValue);
    String ret=new String();
    if(val>0)
        ret="Alice";
    else if(val<0)
        ret="Bob";
    else ret="Tie";
    return ret;
    
}
// Naive Backtracking
int dp(int i,int p,vector<int>& stones,vector<int> sc)
{
    int currwin;
    if(sc[0]>sc[1])
        currwin= 0;
    else if(sc[0]<sc[1])
        currwin =1;
    else currwin =2;
    if(i>=stones.size())
        return currwin;
    else
    {
        int g1=3,g2=3,g3=3;
        sc[p]+=stones[i];
        g1=dp(i+1,(p+1)%2,stones,sc);
        if(i+1<stones.size())
        {
            sc[p]+=stones[i+1];
            g2=dp(i+2,(p+1)%2,stones,sc);
        }
        if(i+2<stones.size())
        {
            sc[p]+=stones[i+2];
            g3=dp(i+3,(p+1)%2,stones,sc);
        }
        if(g1==p||g2==p||g3==p)
            return memo[i][p][currwin]=p;
        if((g1==3||g1==(p+1)%2)&&(g2==3||g2==(p+1)%2)&&(g3==3||g3==(p+1)%2))
            return memo[i][p][currwin]=(p+1)%2;
        return memo[i][p][currwin]=2;
    }  
}
string stoneGameIII(vector<int>& stoneValue) 
{
    vector<int> sc={0,0};
    int val=dp(0,0,stoneValue,sc);
    switch(val)
    {
        case 0: return "Alice";
            break;
        case 1: return "Bob";
            break;
        default: return "Tie";
    }
    return "";
}
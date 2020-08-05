int mod=(int)1e9+7;
int[][][] memo;
int dp(int i,int Llength,int abs,int n)
{
    if(i==n)
        return 1;
    else if(i>0)
    {
        if(memo[i][Llength][abs]>0)
            return memo[i][Llength][abs];
        long q=0;
        if(abs==0)
            q+=dp(i+1,0,1,n);
        q+=dp(i+1,0,abs,n);
        if(Llength<2)
            q+=dp(i+1,Llength+1,abs,n);
        return memo[i][Llength][abs]=(int)(q%mod);
    }
    else
    {
        long q=(long)dp(i+1,0,0,n)+dp(i+1,1,0,n)+dp(i+1,0,1,n);
        return (int)(q%mod);
    }
}
public int checkRecord(int n) 
{
    memo=new int[n][3][2];
    return dp(0,0,0,n);

}
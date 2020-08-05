class Solution {
long mod =1000000007;
int[][] memo1;
int dp1(int i, int j,char[][] board)
{
	if(i<0||j<0||board[i][j]=='X')
		return Integer.MIN_VALUE;
	if(i==0&&j==0)
		return 0;
	if(memo1[i][j]!=0)
		return memo1[i][j];
	int q=(i==board.length-1&&j==board.length-1)?0:board[i][j]-'0';
	int val=Integer.MIN_VALUE;
	val=Math.max(val,dp1(i-1,j,board));
	val=Math.max(val,dp1(i,j-1,board));
	val=Math.max(val,dp1(i-1,j-1,board));	
	return memo1[i][j]=val>Integer.MIN_VALUE?val+q:Integer.MIN_VALUE;
}
int[][][] memo2;
int dp2(int i,int j,char[][] board,int sum)
{
	if(i>=board.length||j>=board.length||board[i][j]=='X')
		return 0;
	if(i==board.length-1&&j==board.length-1)
    {
		if(sum==0)
			return 1;
		else return 0;
    }
	if(memo2[i][j][sum]!=-1)
		return memo2[i][j][sum];
	else
	{
		int val=(i==0&&j==0)?0:board[i][j]-'0';
        long temp=(long)dp2(i+1,j,board,sum-val)+dp2(i,j+1,board,sum-val)+dp2(i+1,j+1,board,sum-val);
		return memo2[i][j][sum]=(int)(temp%mod);
	}

}

    public int[] pathsWithMaxScore(List<String> b) 
    {
    int n=b.size();
        char[][] board=new char[n][n];
        for(int i=0;i<n;++i)
        {
            String temp=b.get(i);
            for(int j=0;j<n;++j)
                board[i][j]=temp.charAt(j);
        }
    memo1=new int[n][n];
    int i=Math.max(0,dp1(n-1,n-1,board)),j=0;
    if(i>0)
    {
        memo2=new int[n][n][i+1];
        for(int[][] a:memo2)
            for(int[] ba:a)
                Arrays.fill(ba,-1);
   	    j=dp2(0,0,board,i);
    }
    else if(i==0&&board[1][1]=='S')
        j=1;
        int [] ret=new int[2];
        ret[0]=i;
        ret[1]=j;
        return ret;
    }
}	
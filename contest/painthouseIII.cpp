
int dp(int i,vector<int> h,int n,int target,vector<vector<int>>& cost)
{
	if(i>=h.size())
		if(n==target)
			return 0;
		else return 10000;
    if(h[i]!=0)
        return dp(i+1,h,n,target,cost);
    else
    {
        int q=10000;
        if(i>0&&i+1<h.size()&&h[i+1]==h[i-1])
        {
            h[i]=h[i+1];
            q=min(q,cost[i][h[i+1]-1]+dp(i+1,h,n-1,target,cost));
        }
        else
        {
            if(i+1<h.size()&&h[i+1]!=0)
            {
                h[i]=h[i+1];
                q=min(q,cost[i][h[i+1]-1]+dp(i+1,h,n,target,cost));
            }
            if(i>0)
            {
                h[i]=h[i-1];
                q=min(q,cost[i][h[i-1]-1]+dp(i+1,h,n,target,cost));		
            }
        }
        for(int j=0;j<cost[i].size();++j)
            if((i+1<h.size()&&h[i+1]==j+1)||(i>0&&h[i-1]==j+1))
                continue;
            else
            {
                h[i]=j+1;
                q=min(q,cost[i][j]+dp(i+1,h,n+1,target,cost));
            }
        return q;
     }
}
int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n, int target) 
{
	int nhood=0;
    if(h.size()&&h[0])
        ++nhood;
	for(int i=1;i<h.size();++i)
		if(h[i]!=h[i-1]&&h[i])
			++nhood;
	if(nhood>target)
		return -1;
	else
    {
        int val=dp(0,h,nhood,target,cost);
        return val<10000?val:-1;
    }
}
// the above code memoized
int[][][] memo;
int dp(int i,int[] h,int[][]cost,int n,int target)
{
    if(i>=h.length)
        if(n==target)
            return 0;
        else return 100000;
    if(h[i]!=0)
        return dp(i+1,h,cost,n,target);
    int prev_color=i>0?h[i-1]:0;
    if(memo[i][prev_color][n]>0)
        return memo[i][prev_color][n];
    else
    {
        int q=100000;
        if(i>0&&i+1<h.length&&h[i+1]==h[i-1])
        {
            h[i]=h[i+1];
            q=Math.min(q,cost[i][h[i+1]-1]+dp(i+1,h,cost,n-1,target));
        }
        else
        {
            if(i+1<h.length&&h[i+1]!=0)
            {
                h[i]=h[i+1];
                q=Math.min(q,cost[i][h[i+1]-1]+dp(i+1,h,cost,n,target));
                h[i]=0;
            }
            if(i>0)
            {
                h[i]=h[i-1];
                q=Math.min(q,cost[i][h[i-1]-1]+dp(i+1,h,cost,n,target));
                h[i]=0;
            }
        }
        for(int j=0;j<cost[i].length;++j)
            if((i>0&&j+1==h[i-1])||(i+1<h.length&&h[i+1]==j+1))
                continue;
            else
            {
                h[i]=j+1;
                q=Math.min(q,cost[i][j]+dp(i+1,h,cost,n+1,target));
                h[i]=0;
            }
        return memo[i][prev_color][n]=q;
    }
}
public int minCost(int[] h, int[][] cost, int m, int n, int target) 
{
    int nhood=0;
    if(h.length>0&&h[0]!=0)
        ++nhood;
    for(int i=1;i<h.length;++i)
        if(h[i]!=h[i-1]&&h[i]!=0)
            ++nhood;
    //System.out.println(nhood);
   /* if(nhood>target)
        return -1;*/
    memo=new int[m][n+1][101];
    int val= dp(0,h,cost,nhood,target);
    return val<100000?val:-1;
}
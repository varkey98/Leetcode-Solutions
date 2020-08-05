HashMap<Integer,Integer> adj1;
HashMap<Integer,Integer> adj2;
long[][] memo;
long mod=(long)1e9+7;
long dp(int i,int[] nums1,int[] nums2,int flag)
{
    if(flag==1)
    {
        if(i>=nums1.length)
            return 0;
        else
        {
            if(memo[i][flag]!=0)
                return memo[i][flag];
            long q=(long)nums1[i];
            if(adj2.containsKey(nums1[i]))
                q+=dp(adj2.get(nums1[i])+1,nums1,nums2,0);
            q=Math.max(q,nums1[i]+dp(adj1.get(nums1[i])+1,nums1,nums2,flag));
            return memo[i][flag]=/*(int)(q%mod)*/q;
        }
    }
    else
    {
        if(i>=nums2.length)
            return 0;
        else
        {
            if(memo[i][flag]!=0)
                return memo[i][flag];
            long q=(long)nums2[i];
            if(adj1.containsKey(nums2[i]))
                q+=dp(adj1.get(nums2[i])+1,nums1,nums2,1);
            q=Math.max(q,nums2[i]+dp(adj2.get(nums2[i])+1,nums1,nums2,flag));
            return memo[i][flag]=/*(int)(q%mod)*/q;
        }
    }
}
public int maxSum(int[] nums1, int[] nums2) 
{
    adj1=new HashMap<Integer,Integer>();
    adj2=new HashMap<Integer,Integer>();
    for(int i=0;i<nums1.length;++i)
        adj1.put(nums1[i],i);
    for(int i=0;i<nums2.length;++i)
        adj2.put(nums2[i],i);
    memo=new long[Math.max(nums1.length,nums2.length)+1][2];
    return (int)(Math.max(dp(0,nums1,nums2,1),dp(0,nums1,nums2,0))%mod);
}
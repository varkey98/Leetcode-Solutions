vector<int> memo1;
int dp1(int i,vector<int>& nums)
{
    if(memo1[i]!=-1)
        return memo1[i];
    int q=0;
    for(int j=i+1;j<nums.size();++j)
        if(nums[j]>nums[i])
            q=max(q,1+dp1(j,nums));
    q=max(q,1);
    return memo1[i]=q;
}
vector<vector<int>> memo2;
int dp2(int i,int num,vector<int>& nums)
{
    if(num==1)
        return 1;
    else if(memo2[i][num]!=-1)
        return memo2[i][num];
    else
    {
        int q=0;
        for(int j=i+1;j<nums.size();++j)
            if(nums[j]>nums[i])
                q+=dp2(j,num-1,nums);
        return memo2[i][num]=q;                                
    }
}
int findNumberOfLIS(vector<int>& nums) 
{
    memo1.resize(nums.size(),-1);
    int num=0;
    for(int i=0;i<nums.size();++i)
        num=max(num,dp1(i,nums));
    memo2.resize(nums.size(),vector<int>(num+1,-1));
    int q=0;
    for(int i=0;i<nums.size();++i)
        q+=dp2(i,num,nums);
    return q;
}

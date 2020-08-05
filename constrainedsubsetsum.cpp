unordered_map<int,int> r;
int dp(vector<int>&nums,int start,int k)
{
    if(start<nums.size())
    {
        if(r.count(start))
            return r[start];
        int q=INT_MIN;
        for(int i=start+1;i<=start+k&&i<nums.size();++i)
                q=max(q,nums[start]+dp(nums,i,k));
        q=max(q,nums[start]);
        r[start]=q;
        return q;
    }
    else return 0;
}
int constrainedSubsetSum(vector<int>& nums, int k) {
    int q=INT_MIN;
   // vector<int> r(nums.size(),q);
    for(int i=0;i<nums.size();++i)
        q=max(q,dp(nums,i,k));
    return q;
}

class Solution {
public:
    vector<int> memo;
    int m;
    int dfs(int i,vector<int>& nums)
    {
        if(memo[i]!=-1)
            return memo[i];
        int q=1;
        int flag=true;
        for(int j=i+1;j<nums.size();++j)
            if(nums[j]%nums[i]==0)
                q=max(q,1+dfs(j,nums));
        memo[i]=q;
        if(memo[i]>m)
          m=memo[i];
        return q;
                
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memo.resize(nums.size(),-1);
        vector<int> ret;
        for(int i=0;i<nums.size();++i)
            dfs(i,nums);
        for(int i=0;i<nums.size();++i)
            if(memo[i]==m)
            {
                ret.push_back(nums[i]);
                --m;
            }
        return ret;
    }
};
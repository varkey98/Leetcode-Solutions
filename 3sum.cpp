vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ret;
    sort(nums.begin(),nums.end());
    if(nums.size()<3)
        return {};
    for(int i=0;i<=nums.size()-3;++i)
    {
        if(i>0&&nums[i]==nums[i-1])
            continue;
        int sum=-1*nums[i];
        int fp=i+1;
        int lp=nums.size()-1;
        while(fp<lp)
        {
            int cSum=nums[fp]+nums[lp];
            if(cSum==sum)
            {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[fp]);
                v.push_back(nums[lp]);
                ret.push_back(v);
                ++fp;--lp;
                while(fp<nums.size()-1&&nums[fp]==nums[fp-1]) ++fp;
                while(lp>0&&nums[lp]==nums[lp+1]) --lp;
            }
            else if(cSum<sum)
                ++fp;
            else
                --lp;
            
        }
            
    }
    return ret;
}
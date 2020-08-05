int fun(vector<int>&nums,int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        return fun(nums,p,q)^fun(nums,q+1,r);
    }
    else if(p==r)
        return nums[p];
    else
        return 0;
}
int singleNonDuplicate(vector<int>& nums) {
    return fun(nums,0,nums.size()-1);
}
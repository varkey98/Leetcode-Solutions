vector<vector<int>> grey;
vector<vector<int>> memo;
vector<int> dp(int i,int k,vector<int>& arr,vector<int>& ret)
{
	if(k==0)
		return ret;
	else if(i>=arr.size())
		return {};
	else if(grey[i][k])
		return memo[k];
	else
	{
		vector<int> not_taken=dp(i+1,k,arr,ret);
		ret.push_back(arr[i]);
		vector<int> taken=dp(i+1,k-1,arr,ret);
		grey[i][k]=true;
		if(taken.size()>not_taken.size())
			return memo[l]=taken;
		else if(not_taken.size()>taken.size())
			return memo[l]=not_taken;
		else
			for(int j=0;j<taken.size();++j)
				if(not_taken[j]>taken[j])
					return memo[l]=not_taken;
		return memo[k]=taken;
	}
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
    int n=nums1.size();
    memo.resize(k+1);
    grey.resize(n,vector<int>(k+1,0));
    vector<int> temp;
    return dp(0,k,nums1,temp);
}
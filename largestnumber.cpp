vector<vector<vector<string>>> memo;//TLE
string dp(int i,int j,vector<int>& n1,vector<int>& n2,int z)
{
	if(z==0||(i>=n1.size()&&j>=n2.size()))
		return "";
	if(memo[i][j][z]!="")
		return memo[i][j][z];
	string a,b,q;
	for(int k=i;k<n1.size();++k)
	{
		q=to_string(n1[k])+dp(k+1,j,n1,n2,z-1);
		if(q.length()==z&&a.compare(q)<0)
			a=q;
	}
	for(int k=j;k<n2.size();++k)
	{
		q=to_string(n2[k])+dp(i,k+1,n1,n2,z-1);
		if(q.length()==z&&b.compare(q)<0)
			b=q;
	}
	if(a.compare(b)>=0)
		return memo[i][j][z]=a;
	else return memo[i][j][z]=b;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
    memo.resize(nums1.size()+1,vector<vector<string>>(nums2.size()+1,vector<string>(k+1,"")));
    string temp=dp(0,0,nums1,nums2,k);
    vector<int> ret;
    for(char x:temp)
    	ret.push_back(x-'0');
    return ret;
}
/////
vector<vector<vector<string>>> memo;
string dp(int i,int j,vector<int>& n1,vector<int>& n2,int z)
{
	if(z==0||(i>=n1.size()&&j>=n2.size()))
		return "";
	if(memo[i][j][z]!="")
		return memo[i][j][z];
	string not_taken=dp(i+1,j+1,n1,n2,z);
	string taken;
	if(n1[i]>n2[j])
		taken=to_string(n1[i])+dp(i+1,j,n1,n2,z-1);
	else
		taken=to_string(n2[j])+dp(i,j+1,n1,n2,z-1);
	if(not_taken.size()==z&&not_taken.compare(taken)>=0)
		return memo[i][j][z]=not_taken;
	else return memo[i][j][z]=taken;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
{
    memo.resize(nums1.size()+1,vector<vector<string>>(nums2.size()+1,vector<string>(k+1,"")));
    string temp=dp(0,0,nums1,nums2,k);
    vector<int> ret;
    for(char x:temp)
    	ret.push_back(x-'0');
    return ret;
}





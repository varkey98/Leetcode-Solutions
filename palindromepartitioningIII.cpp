int makePalindrome(int i,int j,string s)
{
	int len=j-i+1;
	int ret=0;
	for(int k=0;k<len/2;++k)
		if(s[i+k]!=s[j-k])
			++ret;
	return ret;
}
vector<vector<int>> memo;
int dp(int i,int k,string& s,vector<vector<int>>& count)
{
	if(k==0&&i==s.length())
		return 0;
	else if(k==0||i>=s.length())
		return 101;
	else if(memo[i][k]!=-1)
		return memo[i][k];
	else
	{
		int q=101;
		for(int j=i;j<s.length();++j)
			q=min(q,count[i][j]+dp(j+1,k-1,s,count));
		return memo[i][k]=q;
	} 
}
int palindromePartition(string s, int k) 
{
	int n=s.length();
	vector<vector<int>> count(n,vector<int>(n,0));
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			count[i][j]=makePalindrome(i,j,s);
	memo.resize(n,vector<int>(k+1,-1));
	return dp(0,k,s,count);
}
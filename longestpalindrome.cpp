int start=0,end,length=1;
vector<vector<int>> memo;
bool dp(int i,int j,string& s)
{
	if(i<0||j<0||i>=s.length()||j>=s.length()||i>j)
		return 1;
	if(memo[i][j]!=-1)
		return memo[i][j];
	if(i==j)
		return 1;
	int q;
	if(s[i]==s[j]&&dp(i+1,j-1,s))
    {
		q=j-i+1;
		if(q>length)
		{
			length=q;
			start=i;
			end=j;
		}
		return memo[i][j]=1;
    }
	else
	{
		dp(i+1,j,s)+dp(i,j-1,s);
		return memo[i][j]=0;
	}
}
string longestPalindrome(string s) 
{
	memo.resize(s.length(),vector<int>(s.length(),-1));
	cout<<dp(0,s.length()-1,s);
	return s.substr(start,length);    
}
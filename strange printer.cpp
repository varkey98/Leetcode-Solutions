vector<vector<int>> memo;
int dp(int i,int j,string str)
{
	if(i==j)
		return 1;
	if(i>j)
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int q;
	if(str[i]==str[j])
	{
		int flag=1;
		for(int k=i+1;k<j;++k)
			if(str[k]!=str[i])
			{
				flag=0;
				break;
			}
		if(flag)
			q=1;
		else
			q=1+dp(i+1,j-1,str);
	}
	else
		q=1+min(dp(i,j-1,str),dp(i+1,j,str));
	return memo[i][j]=q;
}
int strangePrinter(string str) 
{
	memo.resize(str.length(),vector<int>(str.length(),-1));
	return dp(0,str.length(),str);
}
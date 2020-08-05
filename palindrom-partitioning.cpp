vector<vector<string>> ret;// just memoizes all the palindromic substrings. instead of(n*2^n), its (n^2+2^n)
vector<vector<bool>> memo;
void dfs(int i,int j,string s,vector<string> v)
{
	if(j==s.length())//i>j
    {
        if(v.size())
		    ret.push_back(v);
        return;
    }
	int flag=1;
	/*int start=i,end=j;
	while(start<end)
		if(s[start]==s[end])
		{
			++start;
			--end;
		}
		else
		{
		 flag=0;  
		 break;
		}*/
	if(!memo[i][j])
		flag=0;
	if(flag)
	{
		v.push_back(s.substr(i,j-i+1));
		dfs(j+1,j+1,s,v);
        v.pop_back();
	}
    if(j+1<s.length())
	    dfs(i,j+1,s,v);

}
vector<vector<string>> partition(string s) 
{
	memo.resize(n, vector<bool>(n, false));
    //   build dp : if i through j (inclusive) makes a palindrome, dp[i][j] = true;
    for(int l = 1; l <=n; l++)
      for(int i = 0; i < n; i++)
      {
        int j = i + l - 1;
        if(j >= n) break;
        memo[i][j] = (i + 1 > j - 1 || memo[i + 1][j - 1]) && s[i] == s[j];
      }
	dfs(0,0,s,{});
	return ret;
}
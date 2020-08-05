vector<vector<int>> memo;
int dp(int mask,int i,vector<string>& words, vector<int>& score,vector<int> count)
{
	if(i>=words.size())
		return 0;
	if(memo[mask][i]!=-1)
		return memo[mask][i];
	int q=dp(mask,i+1,words,score,count);
	string s=words[i];
	int val=0;bool flag=true;
	for(char x: s)
	{
		if(count[x-'a']>0)
		{
			val+=score[x-'a'];
			count[x-'a']--;
		}
		else flag=false;
	}
	if(flag)
		q=max(q,val+dp(mask|1<<i,i+1,words,score,count));
	return memo[mask][i] = q;
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
{
    vector<int> count;
	int allmask=(1<<words.size())-1;
	count.resize(26,0);
	for(char x:letters)
		count[x-'a']++;
	memo.resize(allmask,vector<int>(letters.size(),-1));
	return dp(0,0,words,score,count);

}
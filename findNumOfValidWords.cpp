vector<int> ret;
/*void  fun(vector<int>& wordMask,vector<int>& puzzleMask,vector<string>& puzzles)
{
	for(int word:wordMask)
		for(int i=0;i<puzzleMask.size();++i)
		{
			int puzzle=puzzleMask[i];
			int firstChar=1<<(puzzles[i][0]-'a');
			if(((puzzle&word)==word)&&((word&firstChar)!=0))
				ret[i]++;
		}
}*/
void fun(map<int,int>& wordMask,vector<int>& puzzleMask,vector<string>& puzzles)
{
	for(int i=0;i<puzzleMask.size();++i)
	{
		int puzzle=puzzleMask[i];
		int firstChar=1<<(puzzles[i][0]-'a');
		for(auto itr=wordMask.begin();itr!=wordMask.end();++itr)
		{
			int word=itr->first;
			if(((puzzle&word)==word)&&((word&firstChar)!=0))
				ret[i]+=itr->second;
		}
	}
}
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
{
    vector<int> puzzleMask;
    for(string s:puzzles)
    {
    	int mask=0;
    	for(char x:s)
    		mask=mask|1<<(x-'a');
    	puzzleMask.push_back(mask);
    }
    ret.resize(puzzles.size(),0);
   	/*vector<int> wordMask;
   	for(string s: words)
   	{
   		int mask=0;
   		for(char x:s)
   			mask=mask|1<<(x-'a');
   		wordMask.push_back(mask);
   	}*/
   	map<int,int> wordMask;
   	for(string s:words)
   	{
   		int mask=0;
   		for(char x:s)
   			mask=mask|1<<(x-'a');
   		wordMask[mask]++;
   	}
    fun(wordMask,puzzleMask,puzzles);
   	return ret;
}
//
vector<int> ret;
int dp(int mask,string str,int index,map<int,int>& s)
{
	if(index>=str.length())
		return 0;
	int q=dp(mask,str,index+1,s);
	mask=mask|1<<(str[index]-'a');
	q+=dp(mask,str,index+1,s);
	if(s.find(mask)!=s.end())
		return q+s[mask];
	else return q;
}
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
{
    ret.resize(puzzles.size(),0);
   	map<int,int> s;
   	for(string str:words)
   	{
   		int mask=0;
   		for(char x:str)
   			mask=mask|1<<(x-'a');
   		s[mask]++;
   	}
    for(int i=0;i<puzzles.size();++i)
    {
    	string str=puzzles[i];
    	int mask=0;mask|=1<<(str[0]-'a');
        if(s.find(mask)!=s.end())
            ret[i]=s[mask];
    	ret[i]+=dp(mask,str,1,s);
    }
   	return ret;
}
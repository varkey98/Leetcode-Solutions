map<string,vector<string>> memo;
vector<string> dp(string s,vector<string>& d)
{
	if(s.length()==0)
		return {};
	if(memo.find(s)!=memo.end())
		return memo[s];
	vector<string> ret;
	for(string x:d)
	{
		int l=x.length();
		string str=s.substr(0,l);
		if(str.compare(x)==0)
		{
			vector<string> temp=dp(s.substr(l),d);
			if(!s.substr(l).size())
			{
				ret.push_back(str);
				//return memo[s]= temp;
			}
			else
				for(string a:temp)
				{
					//x+=" "+a;
					ret.push_back(x+" "+a);
				}
		}
	}
	return memo[s]=ret;
}
vector<string> wordBreak(string s, vector<string>& wordDict) 
{
    //string ret;
    cout<<endl;
    vector<string> ret= dp(s,wordDict);
    return ret;
}
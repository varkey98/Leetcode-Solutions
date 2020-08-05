map<int,int> pc;
vector<int> sc;
bool isAnagram()
{
	for(auto itr=pc.begin();itr!=pc.end();++itr)
		if(sc[itr->first]!=itr->second)
			return false;
	return true;
}
vector<int> findAnagrams(string s, string p) 
{
	vector<int> ret;
	int n=p.length();
	if(s.length()<n)
		return ret;
	sc.resize(26,0);
	for(char x:p)
		pc[x-'a']++;
	int i=0;
	for(;i<n;++i)
		sc[s[i]-'a']++;
    i=0;
	while(true)
	{
		if(isAnagram())
			ret.push_back(i);
		++i;
		sc[s[i-1]-'a']-=1;
		if(i+n>s.length())
			break;
		else
			sc[s[i+n-1]-'a']+=1;

	}
	return ret;    
}
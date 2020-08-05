string parseString(string str)
{
	string ret;
	for(string::iterator itr=str.begin();itr!=str.end();++itr)
	{
		if(*itr=='#')
		{
			if(ret.length())
				ret.pop_back();
		}
		else
			ret.push_back(*itr);
	}
	return ret;
}
bool backspaceCompare(string S, string T)
{
	S=parseString(S);
	T=parseString(T);
	if(!S.compare(T))
		return true;
	else return false;
}
string countOfAtoms(string formula)
{
	map<string,int> m;
	map<string,int> ret;
	char arr[formula.length()];
	int i=0;
	string temp;
	formula.copy(arr,formula.length(),0);
	stack<char> s;    
	for(int i=0;i<formula.length();++i)
	{
		if(arr[i]=='(')
		{
			int c=1;
			while(c)
			{
				s.push(arr[i]);
				if(arr[i]=='(')
					++c;
				else if(arr[i]==')')
					--c;
			}
		}
		else if(arr[i]>='A'&&arr[i]<='Z')
		{
			if(temp.length())
				m[temp]+=1;
			temp.clear();
			temp.push_back(arr[i]);
		}
		else if(arr[i]>='0'&&arr[i]<='9')
		{
			if(temp.length())
			{
				m[temp]+=arr[i]-48;
				temp.clear();
			}
		}
		else (arr[i]>='a'&&arr[i]<='z')
			temp.push_back(arr[i]);
	}  
	map<string, int>::iterator itr;
	if(temp.length())
				m[temp]+=1;
			temp.clear();
	for(itr=m.begin();itr!=m.end();++itr)
	{
		temp.append(itr->first);
		if(itr->second>1)
			temp.push_back(itr->second+48);	
	} 
	return temp;
}
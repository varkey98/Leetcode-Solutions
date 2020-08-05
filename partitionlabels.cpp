vector<int> partitionLabels(string s) 
{
	int	n=s.length();
	vector<int> last(n,0);
	for(int i=0;i<n;++i)
		last[s[i]]=i;
	int prev=-1;
	vector<int> ret;
	for(int i=0;i<n;++i)
		if(last[s[i]]==i)
		{
			bool flag=true;
			for(int j=prev+1;j<i;++j)
				if(last[s[j]]>i)
					flag=false;
			if(flag)
			{
				ret.push_back(prev-i);
				prev=i;
			}
		}
	return ret;
}
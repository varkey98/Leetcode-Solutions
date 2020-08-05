int countElements(vector<int>& arr)
{
	int ret=0;
	map<int,bool> m;
	for(int i=0;i<arr.size();++i)
		m[arr[i]]=true;
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();++i)
		if(m.count(arr[i]+1))
			ret++;
	return ret;
}
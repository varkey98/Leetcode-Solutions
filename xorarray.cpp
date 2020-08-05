#include<iostream>

int xorF(int a,int b)
{
	vector<int> temp;
	int ret=0;
	while(a!=0 || b!=0)
	{
		temp.push_back((a%2)^(b%2));
		a/=2;
		b/=2;
	}
	if((a==0&&b!=0)||(a!=0&&b==0))
	{
		if(a==0&&b!=0)
			while(b)
			{
				temp.push_back((b%2)^0);
				b/=2;
			}
		else
			while(a)
			{
				temp.push_back((a%2)^0);
				a/=2;
			}
	}
	int power=1;
	for(int i=0;i<temp.size();++i)
	{
		ret=ret+power*temp[i];
		power*=2;
	}
	return ret;
}
map<vector<int>,int> m;
int function(vector<int>& arr,vector<int> val)
{
	if(m.find(val)!=m.end())
		return m.find(val)->second;
	else
	{
		int start=val[0];
		int end=val[1];
		if(start==end)
		{
			m[val]=arr[start];
			return arr[start];
		}
		else if(start<end)
		{
			int mid=(start+end)/2;
			vector<int> ret1,ret2;
			ret1.push_back(start);
			ret1.push_back(mid);
			ret2.push_back(mid+1);
			ret2.push_back(end);
			m[val] = function(arr,ret1)^function(arr,ret2);
			return m[val];

		}
		else return 0;
	}

}
 vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
 {
 	vector<int> temp;
 	for (int i=0;i<queries.size();++i)
 		temp.push_back(function(arr,queries[i]));
 	return temp;      
 }
void dp(int mask,vector<string>& arr,int allmask,string str)
{
	if(mask==allmask)
		cout<<str.length()<<endl;
	else
	{
		for(int i=0;i<arr.size();++i)
			if((mask&(1<<i))==0)
			{
				int end=str.length()-1;
				int start=0;
				while(end>=0&&start<arr[i].length()&&str[end]==arr[i][start])
					--end,++start;
				dp(mask|1<<i,arr,allmask,str+arr[i].substr(start));
			}
	}
}
string shortestSuperstring(vector<string>& A) 
{
    int allmask=(1<<A.size())-1;
    dp(0,A,allmask,"");
    return "";
}
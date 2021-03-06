bool check(int a,int b)
{
	double x=sqrt(a+b);
	int y=(int)x;
	if((x-y)==0)
		return true;
	else return false;
}
map<string,int> memo;
int dp(int num,vector<int>& A,int size,string str)
{
	if(size==A.size())
		return 1;
	if(memo.find(str)!=memo.end())
		return memo[str];
	int ret=0;
	for(int i=0;i<A.size();++i)
		if(A[i]!=-1&&check(num,A[i]))
		{
			string s=str;
			s+="|";
			int temp=A[i];
			s+=to_string(temp);
			A[i]=-1;
            if(memo.find(s)==memo.end())//to avoid counting redundant combination.
			    ret+=dp(temp,A,size+1,s);
			A[i]=temp;
		}
	return memo[str]=ret;
}
int numSquarefulPerms(vector<int>& A) 
{
	int q=0;
    for(int i=0;i<A.size();++i)
    {
    	int temp=A[i];
    	A[i]=-1;
    	string s;
    	s=to_string(temp);
        if(memo.find(s)==memo.end())
    	    q+=dp(temp,A,1,s);
    	A[i]=temp;
    }
    return q;
}
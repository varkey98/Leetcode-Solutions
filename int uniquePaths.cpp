typedef pair<int,int> cood;
int fun(cood p,int m,int n,map<cood,int>& arr)
{
	if(arr.count(p))
		return arr[p];
	else if(p.first==m&&p.second==n)
		return 1;
	else if(p.first>m||p.second>n)
		return 0;
	else 
	{
		cood t1,t2;
		t1.first=p.first+1;
		t1.second=p.second;
		t2.first=p.first;
		t2.second=p.second+1;
		arr[p]= fun(t1,m,n,arr)+fun(t2,m,n,arr);
		return arr[p];
	}
}
int uniquePaths(int m, int n) {
	//int n=0;
	cood p;
	map<cood,int> arr;
	p.first=1;
	p.second=1;
	return fun(p,m,n,arr);

        
    }
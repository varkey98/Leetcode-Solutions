vector<int> memo;
int c=0;
int dfs(int i,int d,vector<int>& arr)
{
	if(i>=arr.size())
		return 0;
	if(i==arr.size()-1)
		return 1;
	if(memo[i]!=-1)
		return memo[i];
	memo[i]=1+dfs(i+1,arr[i+1]-arr[i],arr);
    if(memo[i]>2)
        c+=memo[i]-2;
	if(arr[i+1]-arr[i]==d)
		return memo[i];
	else
		return 1;
}
int numberOfArithmeticSlices(vector<int>& arr)
{
	memo.resize(arr.size(),-1);
	dfs(0,0,arr);
	return c;
}
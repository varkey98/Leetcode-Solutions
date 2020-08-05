vector<vector<int>> memo;
int dp(int i,int j,string ring,string key)
{
	if(j>=key.size())
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int q;
	if(ring[i]==key[j])
		q=1+dp(i,j+1,ring,key);
	else
	{

		int left=1000,right=1000;
		for(int k=0;k<i;++k)//should rotate the dials clokcwise and anti-clockwise
			if(ring[k]==key[j])
				left=min(left,i-k+dp(k,j,ring,key));
		for(int k=i+1;k<ring.size();++k)
			if(ring[k]==key[j])
				right=min(right,k-i+dp(k,j,ring,key));
		q=min(left,right);
	}
	return memo[i][j]=q;
}
int findRotateSteps(string ring, string key) 
{
    memo.resize(ring.size(),vector<int>(key.size(),-1));
    return dp(0,0,ring,key);
}

vector<vector<int>> memo;
int dp(int i,int j,string ring,string key)
{
	if(j>=key.size())
		return 0;
	if(memo[i][j]!=-1)
		return memo[i][j];
	int q;
	if(ring[i]==key[j])
		q=1+dp(i,j+1,ring,key);
	else
	{

		int left=1000,right=1000,steps=0;
		for(int k=i>0?i-1:ring.length()-1;k!=i;k=k>0?--k:ring.length()-1)
		{
			++steps;
			if(ring[k]==key[j])
				left=min(left,steps+dp(k,j,ring,key));
		}
		steps=0;
		for(int k=i+1;k!=i;k=(k+1)%ring.length())
		{
			++steps;
			if(ring[k]==key[j])
				right=min(right,steps+dp(k,j,ring,key));
		}
		q=min(left,right);
	}
	return memo[i][j]=q;
}
int findRotateSteps(string ring, string key) 
{
    memo.resize(ring.size(),vector<int>(key.size(),-1));
    return dp(0,0,ring,key);
}
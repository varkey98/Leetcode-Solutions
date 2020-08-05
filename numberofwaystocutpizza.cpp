vector<vector<vector<int>>> memo;
int dp(int i,int j,vector<string>& pizza,int k)
{
	if(i>=pizza.size()||j>=pizza[0].length())
		return 0;
	if(memo[i][j][k]!=-1)
		return 0;
	if(!k)
	{
		bool flag=false;
		for(int ver=i;ver<pizza.size();++ver)
			for(int hor=j;hor<pizza[0].length();++hor)
				if(pizza[ver][hor]=='A')
				{
					flag=true;
					break;
				}
		if(flag)
			return 1;
		else return 0;
	}
	bool h=false,v=false;
	for(int hor=j;hor<pizza[0].length();++hor)
		if(pizza[i][hor]=='A')
		{
			h=true;
			break;
		}
	for(int ver=i;ver<pizza.size();++ver)
		if(pizza[ver][j]=='A')
		{
			v=true;
			break;
		}
	int q=0;
	if(h)
		q+=dp(i+1,j,pizza,k-1);
	if(v)
		q+=dp(i,j+1,pizza,k-1);
	q+=dp(i,j+1,pizza,k)+dp(i+1,j,pizza,k);
	return memo[i][j][k]=q;
}
int ways(vector<string>& pizza, int k) 
{
	memo.resize(pizza.size(),vector<vector<int>>(pizza[0].length(),vector<int>(k,-1)));
	return dp(0,0,pizza,k-1);
    int rows=pizza.size();
    int cols=pizza[0].length();
    
}
//*************************************************************************************************************************************************************************
int countApples(int i,int j,vector<vector<int>>& apples,vector<string>& pizza)
{
	
}
int ways(vector<string>& pizza, int k) 
{
	memo.resize(pizza.size(),vector<vector<int>>(pizza[0].length(),vector<int>(k,-1)));
	vector<vector<int>> apples(pizza.size(),vector<int>(pizza[0].length(),-1));
    int rows=pizza.size();
    int cols=pizza[0].length();

	return dp(0,0,pizza,k-1);
    
}
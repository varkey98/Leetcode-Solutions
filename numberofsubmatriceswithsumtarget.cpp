int numSubmatrixSumTarget(vector<vector<int>>& g, int target) //O(n^4) DP, TLE.
{
	int n=g.size();
	int  m=g[0].size();
	int ret=0;
	vector<vector<vector<int>>> memo(n,vector<vector<int>>(m,vector<int>(m,0)));
	for(int i=0;i<n;++i)
	{
		if(i>0)
			for(int j=0;j<m;++j)
				g[i][j]+=g[i-1][j];
			for(int j=0;j<m;++j)
			{
				int val=0;
				for(int k=j;k<m;++k)
				{
					val+=g[i][k];
					memo[i][j][k]=val;
					if(val==target)
						ret++;

				}

			}
			for(int r=i-1;r>=0;--r)
				for(int j=0;j<m;++j)
					for(int k=j;k<m;++k)
						if(memo[i][j][k]-memo[r][j][k]==target)
							ret++;


	}
	return ret;

}
/*vector<vector<int>> adj(n+1);
struct compareCourse
{
	bool operator()(int u, int v)
	{
		return adj[v].size()<adj[v].size();
	}
};*/
int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k)// will work on a single tree, but  won't work on a forest. 
{
	vector<bool> has_pre(n+1,false);
    vector<vector<int>> prereq(n+1);
	for(auto x:dependencies)
	{
		adj[x[0]].push_back(x[1]);
        prereq[x[1]].push_back(x[0]);
		has_pre[x[1]]=true;
	}
	//prority_queue<int,vector<int>,compareCourse> q;
	queue<int> q;
	for(int i=1;i<=n;++i)
		if(has_pre[i]==false)
			q.push(i);
	int ret=0,count=0;
    vector<int> grey(n+1,0);
	while(!q.empty())
	{
		int size=q.size();
		for(int i=0;i<size;++i)
		{
			int u=q.top();
			q.pop();
	        grey[u]=1;
			++count;
			if(count==k)
			{
				++ret;
				count=0;
			}
			for(int v:adj[u])
			{
				bool flag=true;
				for(int x:prereq[v])
	                if(grey[x]==0)
	               		flag=false;
               	if(flag)
               	{
		            q.push(v);
		            grey[v]=-1;
               	}
			}			
		}
		if(count)
			++ret;
	}  
	return ret;
}


vector<int> memo;
int dp(int mask,int allmask,vector<vector<int>>& prereq,int k,int count)
{
	if(mask==allmask)
	{
		if(count)
			return 1;
		else return 0
	}
	int q=0;
	for(int i=1;i<prereq.size();++i)
		if((mask&(1<<i))==0)
		{
			bool flag=true;
			for(int u:prereq[i])
				if((mask&(1<<u))==0)
					flag=false;
			if(flag)
				if(count+1==k)
					q=min(q,1+dp(mask|1<<i,allmask,prereq,k,0));
				else q=min(q,dp(mask|1<<i,allmask,prereq,k,count+1));
		}
	return memo[mask]=q;

}

int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) 
{
	int allmask=(1<<n)-1;
	memo.resize(allmask,-1);
	vector<vector<int>> prereq(n+1);
	for(auto x:dependencies)
		prereq[x[1]].push_back(x[0]);
	return dp(0,allmask,prereq,k,0);
}
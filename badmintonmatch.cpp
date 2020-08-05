#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//queue<pair<int,int>> q;
bool cycle=false;
vector<vector<int>> grey;
void dfs(int i,int j,vector<vector<int>>& adj)
{
	grey[i][j]=grey[j][i]=-1;
	for(int t=0;t<adj[i].size()&&adj[i][t]!=j;++t)
		if(grey[i][adj[i][t]]==0)
			dfs(i,adj[i][t],adj);
		else if(grey[i][adj[i][t]]==-1)
		{
			cycle=true;
			break;
		}
	for(int t=0;t<adj[j].size()&&adj[j][t]!=i;++t)
		if(grey[j][adj[j][t]]==0)
			dfs(j,adj[j][t],adj);
		else if(grey[j][adj[j][t]]==-1)
		{
			cycle=true;
			break;
		}
	//q.push({i,j});
	grey[i][j]=grey[j][i]=1;
}
vector<vector<int>> memo;
int dp(int i,int j,vector<vector<int>>& adj)
{
	if(memo[i][j]!=-1)
		return memo[i][j];
	else
	{
		int ret=1;
		for(int t=0;t<adj[i].size()&&adj[i][t]!=j;++t)
			ret=max(ret,1+dp(i,adj[i][t],adj));
		for(int t=0;t<adj[j].size()&&adj[j][t]!=i;++t)
			ret=max(ret,1+dp(j,adj[j][t],adj));
		return memo[i][j]=memo[j][i]=ret;
	}
}
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;++i)
    	for(int j=0;j<n-1;++j)
    	{
    		int temp;
    		cin>>temp;
    		adj[i].push_back(temp);
    	}
	grey.resize(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i==j||grey[i][j]!=0)
				continue;
			else dfs(i,j,adj);
	if(cycle)
		cout<<-1;
	else
	{
		int ret=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i==j)
					continue;
				else ret=max(ret,dp(i,j,adj));
		cout<<ret;
	}
    return 0;
}

#include<vector>
using namespace std;

void traversal(vector<int>& ret, vector<vector<int>>& graph,vector<vector<int>>& retgraph,int i)
{
	if(i==graph.size()-1)
		retgraph.push_back(ret);
	else if(graph[i].size())
	{
		for(int v:graph[i])
			{
				ret.push_back(v);
				traversal(ret,graph,retgraph,v);
				ret.pop_back();
			}
	}
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<int> ret;
	ret.push_back(0);
	vector<vector<int>> retgraph;
	traversal(ret,graph,retgraph,0);
	return retgraph;
    }
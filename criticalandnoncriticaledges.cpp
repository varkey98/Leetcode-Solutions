bool fun(vector<int>& v1,vector<int>& v2)
{
    return v1[2]<v2[2];
}
class Solution {
private:
vector<int> ans;
int find(int x,vector<int>& parent)
{
	if(parent[x]!=-1)
		return find(parent[x],parent);
	else return x;
}
bool uni(int x,int y,vector<int>& parent)
{
	int xp=find(x,parent);
	int yp=find(y,parent);
	if(xp!=yp)
		parent[yp]=xp;
	else return false;
	return true;
}
public:
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
{
    vector<vector<int>> index(n,vector<int>(n));
    vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
    vector<int> _1,_2;
    for(int i=0;i<edges.size();++i)
        if(adj[edges[i][0]][edges[i][1]]>edges[i][2])
        {
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            index[edges[i][0]][edges[i][1]]=i;
        }
    sort(edges.begin(),edges.end(),fun);
    int size=edges.size();
    int ans=0;
	vector<int> parent(n,-1);
    for(int i=0;i<edges.size();++i)
    	if(uni(edges[i][0],edges[i][1],parent))
    		ans+=edges[i][2];
    for(int i=0;i<size;++i)
    {
    	int temp=0,k=n;
    	vector<int> p(n,-1);
        for(int j=0;j<size;++j)
    		if(i==j)
    			continue;
    		else if(uni(edges[j][0],edges[j][1],p))
    		{
    			temp+=edges[j][2];
    			--k;
    		}
        int t=index[edges[i][0]][edges[i][1]];
    	if(temp>ans||k>1)
    		_1.push_back(t);
        else
        {
            temp=edges[i][2],k=n-1;
            vector<int> p(n,-1);
            uni(edges[i][0],edges[i][1],p);
            for(int j=0;j<size;++j)
                if(i==j)
                    continue;
                else if(uni(edges[j][0],edges[j][1],p))
                {
                    temp+=edges[j][2];
                    --k;
                }
            if(temp==ans&&k==1)
                _2.push_back(t);
        }

    }
    return {_1,_2};
}
};
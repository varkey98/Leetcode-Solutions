int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
{
    unordered_map<int,int> count;
    for(int x:arr)
        count[x]++;
	vector<pair<int,int>> fin;
	for(auto itr=count.begin();itr!=count.end();++itr)
		fin.push_back({itr->second,itr->first});
	sort(fin.begin(),fin.end());
	int val=0,i;
	for(i=0;i<fin.size();++i)
		if(val+fin[i].first<=k)
			val+=fin[i].first;
		else break;
	return fin.size()-i;
}

class TreeAncestor {
public:
    vector<int> p;
    int size;
    vector<vector<int>> memo;
    vector<int> arr;
    TreeAncestor(int n, vector<int>& parent) {
        p=parent;
        size=n;
        memo.resize(n,vector<int>(n,-5));
        arr.resize(n,-5);
    }
    
    int getKthAncestor(int node, int k) {
    	if(k>=size)
    		return -1;
    	if(memo[node][k]!=-5)
    		return memo[node][k];
    	if(!k)
    		return node;
    	else return memo[node][k]=getKthAncestor(p[node],k-1);
    	}
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
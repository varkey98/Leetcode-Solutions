int sum(TreeNode* root,map<TreeNode*,int>& msum,map<int,int>& m)
{
	if(msum.count(root))
		return msum[root];
	if(root)
	{
		int s=root->val+sum(root->left,msum)+sum(root->right,msum);
		msum[root]=s;
		m[s]+=1;
		return s;
	}
	else return 0;
}
   
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> m;
        map<TreeNode*,int> msum;
        sum(root,msum,m);
        map<int,int>::iterator itr=m.begin();
        int max=itr->second;
        vector<int> ret;
        for(;itr!=m.end;++itr)
        	if(max>itr->second)
        		max=itr->second;
        for(itr=m.begin();itr!=m.end();++itr)
        	if(itr->second==max)
        		ret.push_back(itr->first);
        return ret;
    }
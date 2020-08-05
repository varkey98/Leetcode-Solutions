    
    map<int,int> m;
    void level(TreeNode* root,int val)
    {
    	if(root!=NULL)
    	{
    	m[val]+=root->val;
    	level(root->left,val+1);
    	level(root->right,val+1);
    }
    //return m;
    }
    int deepestLeavesSum(TreeNode* root) {
    	m.clear();
    	level(root,1);
        return m.rbegin()->second;
    }
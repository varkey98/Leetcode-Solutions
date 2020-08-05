unordered_set<int> m;
void initialize(TreeNode* root,int val,unordered_set<int>& m)
{
	root->val=val;
	m.insert(val);
	if(root->left)
		initialize(root->left,2*val+1,m);
	if(root->right)
		initialize(root->right,2*val+2,m);
}
FindElements(TreeNode* root) {
	initialize(root,0,m);    
    }

    bool find(int target) {
    	if(m.find(target)!=m.end())
    		return true;
    	else return false;
        
    }
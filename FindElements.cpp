map<int,bool> m;
void initialize(TreeNode* root,int val,map<int,bool>& m)
{
	root->val=val;
	m[val]=true;
	if(root->left)
		initialize(root->left,2*val+1);
	if(root->right)
		initialize(root->right,2*val+2);
}
FindElements(TreeNode* root) {
	initialize(root,0,m);    
    }

    bool find(int target) {
    	if(m.find(target)!=m.end())
    		return true;
    	else return false;
        
    }
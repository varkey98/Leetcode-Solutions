 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
TreeNode* pruneTree(TreeNode* root) 
{
	if(root)
	{
		root->right=pruneTree(root->right);
		root->left=pruneTree(root->left);
		if(root->right==NULL&&root->left==NULL&&root->val==0)
			return NULL;
		else return root;
    }	
    else return NULL;
}

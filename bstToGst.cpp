
int sum(TreeNode* root)
{
	if(root!=NULL)
		return root->val+sum(root->right)+sum(root->left);
}
TreeNode* function(TreeNode* root)
{
	if(root->right->right)
		function(root->right);
	else
		root->val=root->val+root->right->val;
	if(root->left)
		
	return root;
}

TreeNode* bstToGst(TreeNode* root) {
	if(root!=NULL)
	{
		while(root->right->right)
			root=root->right;
		root->val=root->val+root->right;
		root->left->val=root->left->val+root->val;
	}
    
    return root;
	}

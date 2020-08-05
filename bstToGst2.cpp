int max=0;
TreeNode* bstToGst(TreeNode* root)
{
	if(root)
	{
		bstToGst(root->right);
		max+=root->val;
		root->val=max;
		bstToGst(root->left);

	}
	return root;
}

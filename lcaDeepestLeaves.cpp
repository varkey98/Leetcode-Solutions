int height(map<TreeNode*,int>& m,TreeNode* root)
{
	if(m.find(root)==m.end())
	{
		if(root)
		{
			m[root]=max(height(m,root->left),height(m,root->right))+1;	
			return m[root];
		}
		else return -1;
	}
	else
		return m[root];
}
TreeNode* traversal(map<TreeNode*,int>& m,TreeNode* root)
{
	if(height(m,root->left)==height(m,root->right))
		return root;
	else if(height(m,root->left)>height(m,root->right))
		return traversal(m,root->left);
	else
		return traversal(m,root->right);
}
TreeNode* lcaDeepestLeaves(TreeNode* root)
{
	map<TreeNode*,int> m;
	height(m,root);
	return traversal(m,root);
}
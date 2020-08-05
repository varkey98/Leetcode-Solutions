bool flipEquiv(TreeNode* root1, TreeNode* root2) 
{
	if(root1&&root2)
	{
		if(root1->val==root2->val)
		{
			return (flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right))||(flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left));
		}
		else return false;
	}
	else if(!root1&&!root2)
		return true;
	else return false;
}
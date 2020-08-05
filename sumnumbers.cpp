void DFSfun(TreeNode* root,int* ret,int csum)
{
	if(root)
	{
		csum*=10;
		csum+=root->val;
		if(root->left==NULL&&root->right==NULL)
			*ret+=csum;
		else
		{
			DFSfun(root->left,ret,csum);
			DFSfun(root->right,ret,csum);
		}
	}
}
int sumNumbers(TreeNode* root)
{
	int ret=0;
	DFSfun(root,&ret,0);
	return ret;
}
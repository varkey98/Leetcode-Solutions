//0 not under surveilance, 1 under surveilance, 2,has a camera
int count=0;
int dfs(TreeNode* root)
{
	if(root)
	{
		int ret;
		int left=dfs(root->left);
		int right=dfs(root->right);
		if(!left||!right)
		{
			count++;
			ret=2;
		}
		else if(left==2||right==2)
			ret=1;
		else ret=0;
		return ret;

	}
	else return 1;
}
int minCameraCover(TreeNode* root)
{
	if(dfs(root)==0)
        ++count;
	return count; 
}
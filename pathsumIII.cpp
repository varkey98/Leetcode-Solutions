void DFS(TreeNode* root,int p,int sum,int* count)
{
	if(root)
	{
		p+=root->val;
		if(p==sum)
		{
			*count+=1;
			DFS(root->left,0,sum,count);
			DFS(root->right,0,sum,count);
		}
		else if(p<sum)
		{
			DFS(root->left,p,sum,count);
			DFS(root->right,p,sum,count);
		}
		else
		{
			DFS(root->left,0,sum,count);
			DFS(root->right,0,sum,count);
		}
	}
}
int pathSum(TreeNode* root, int sum)
{
	int count=0;
	DFS(root,0,sum,&count);
	return count;
}

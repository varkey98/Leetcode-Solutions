void DFSfun(TreeNode* root,vector<int>& path,vector<vector<int>>& ret,int p,int sum)
{
	if(root)
	{
		p+=root->val;
		path.push_back(root->val);
		if(root->left==NULL&&root->right==NULL&&p==sum)
			ret.push_back(path);
		else
		{
			DFSfun(root->left,path,ret,p,sum);
			DFSfun(root->right,path,ret,p,sum);
		}
		path.pop_back();
	}
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
	vector<vector<int>> ret;
	vector<int> path;
	DFSfun(root,path,ret,0,sum);
	return ret;        
}
void depth(map<int,vector<TreeNode*>>& m,TreeNode* root,int level)
{
	if(root)
	{
		if(m.count(level))
			m[level].push_back(root);
		else
		{
			vector<TreeNode*> ret;
			ret.push_back(root);
			m[level]=ret;
		}
		depth(m,root->left,level+1);
		depth(m,root->right,level+1);	//lowest common ancestors of all leaves.
	}	
}
TreeNode* lcaDeepestLeaves(TreeNode* root)
{
	map<int,vector<TreeNode*>> m;
	depth(m,root,0);
	map<int,vector<TreeNode*>>:: iterator itr=m.end();
	--itr;
	while(1)
	{
		if(itr->second.size()==1)
			break;
		else
			--itr;
	}
	return itr->second[0];
}
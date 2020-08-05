void Flevel(TreeNode* root,vector<vector<int>>& ret,int level)
{
	if(root)
	{
		if(level<ret.size())
			ret[level].push_back(root->val);
		else
		{
			vector<int> temp;
			temp.push_back(root->val);
			ret.push_back(temp);
		}
		Flevel(root->left,ret,level+1);
		Flevel(root->right,ret,level+1);
	}
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	queue<int> temp;
	vector<vector<int>> ret;
	Flevel(root,ret,0);
	for(int i=1;i<ret.size();i+=2)
	{
		for(int j=ret[i].size()-1;j>=0;--j)
		{
			temp.push(ret[i][j]);
			ret[i].pop_back();
		}
		while(temp.size())
		{
			ret[i].push_back(temp.front());
			temp.pop();
		}
	} 
	return ret;       
}
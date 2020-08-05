void levelSum(TreeNode* root,map<int,int> &m, int level)
{
	if(root)
	{
		m[level]+=root->val;
		levelSum(root->left,m,level+1);
		levelSum(root->right,m,level+1);
	}
}
int maxLevelSum(TreeNode* root)
 {
 	map<int,int> m;
 	levelSum(root,m,1);
	map<int,int>::iterator itr=m.begin();
	int ret=itr->second;
	int val=itr->first;
	while(itr!=m.end())
	{
		if(itr->second>ret)
		{
			ret=itr->second;
			val=itr->first;
		}
		++itr;
        
    }	
return val;
}

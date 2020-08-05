 void funDFS(map<int,int>& m,TreeNode* root,int level)
 {
 	if(root!=NULL)
 	{
 		m[level]=root->val;
 		funDFS(m,root->right,level+1);
 		funDFS(m,root->left,level+1);
 	}
 } 
int findBottomLeftValue(TreeNode* root)
{
	map<int,int>  m;
	funDFS(m,root,0);
	return m[m.size()-1];        
}
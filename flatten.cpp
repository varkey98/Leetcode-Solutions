
    
void preorder(TreeNode* root,map<int,TreeNode*>& s,int* t)
{
	if(root)
	{
        *t+=1;
		s[*t]=root;
		preorder(root->left,s,t);
		preorder(root->right,s,t);
	}
}
void flatten(TreeNode* root) {
	map<int,TreeNode*> s;
    int t=0;
    if(!root)
        return;
	preorder(root,s,&t);
	map<int,TreeNode*>::iterator itr=s.begin();
	TreeNode* temp=root;
	++itr;
	for(;itr!=s.end();++itr)
	{
        temp->right=itr->second;
        temp->left=NULL;
        temp=temp->right;
     //  cout<<(itr->second)->val;
	}

 }
 TreeNode* inorder(TreeNode* root)
 {
 	if(root==NULL||(root->left==NULL&&root->right==NULL))
 		return root;
 	else if(root->left!=NULL&&root->right!=NULL)
 	{
 		
 	}
 }
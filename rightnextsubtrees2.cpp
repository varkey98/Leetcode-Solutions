map<int,Node*> m;

   void fun(Node* root,int level)
 {
 	if(root)
 	{
 		fun(root->left,level+1);
	 	if(m.count(level))
	 	{
	 		m[level]->next=root;
	 		root->next=NULL;
	 		m[level]=root;
	 	}
	 	else
	 	{
	 		
	 		root->next=NULL;
	 		m[level]=root;
	 	}
	 	fun(root->right,level+1);
	 }
 }
  Node* connect(Node* root) {
        fun(root,0);
        return root;
    }
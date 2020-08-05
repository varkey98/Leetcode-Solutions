 void fun(Node* root,map<int,vector<Node*>>& m,int level)
 {
 	if(root)
 	{
 		fun(root->left,m,level+1);
	 	if(m.count(level))
	 	{
	 		(m[level].at(m[level].size()-1))->next=root;
	 		root->next=NULL;
	 		m[level].push_back(root);
	 	}
	 	else
	 	{
	 		vector<Node*> ret;
	 		root->next=NULL;
	 		ret.push_back(root);
	 		m[level]=ret;
	 	}
	 	fun(root->right,m,level+1);
	 }
 }
  Node* connect(Node* root) {
        map<int,vector<Node*>> m;
        fun(root,m,0);
        return root;
    }
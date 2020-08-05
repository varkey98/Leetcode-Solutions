 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 void function(TreeNode* root,int* x) {
 	if(root)
        if(!(root->val%2))
        {
        	if(root->right)
        	{
        		if(root->right->right)
        			*x+= root->right->right->val;
        		if (root->right->left)
        			*x+= root->right->left->val;
        	}
        	if(root->left)
        	{
        		if(root->left->left)
        			*x+= root->left->left->val;
        	 if(root->left->right)
        			*x+= root->left->right->val;
        	}
        	function(root->left,x);
        	function(root->right,x);
        }
        else
        {
        	function(root->left,x);
        	function(root->right,x);
        }
       
    }
    int sumEvenGrandparent(TreeNode* root)
    {
    	int x=0;
    	function(root,&x);
    	return x;
    }
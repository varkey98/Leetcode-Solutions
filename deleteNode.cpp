 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
    	if(root)
    	{
    		root->right=removeLeafNodes(root->right,target);
    		root->left=removeLeafNodes(root->left,target);
    		if(root->right==NULL&&root->left==NULL&&root->val==target)
    		{
    			free(root);
    			return NULL;
    		}
    		else return root;

    	}
    	else return NULL;
        
    }
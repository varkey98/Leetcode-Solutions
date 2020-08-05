TreeNode* insert(TreeNode* root, int val)
    {
        if(!root)
            return new TreeNode(val);
        else 
            if(val<root->val)
            {
                root->left= insert(root->left,val);
                return root;
            }
        else if(val>root->val)
        {
            root->right= insert(root->right,val);
            return root;
        }
        else return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) { 
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();++i)
            root=insert(root,preorder.at(i));
        return root;
    }
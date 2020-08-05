void inorder(TreeNode* root,int *sum, int l, int r)
    {
        if(root)
        {
            if((root->val>=l)&&(root->val<=r))
                *sum=*sum+root->val;
            inorder(root->right,sum,l,r);
            inorder(root->left,sum,l,r);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        while(root->val<L)
            root=root->right;
        while(root->val>R)
            root=root->left;
        inorder(root,&sum,L,R);
        return sum;
    }
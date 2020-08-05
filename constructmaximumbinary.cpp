TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
            if(val>root->val)
                 root->right=insertIntoBST(root->right,val);
            else
                root->left=insertIntoBST(root->left,val);
             return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int index=0;
        int max=nums[0];
        for(int i=0;i<nums.size();++i)
            if(nums[i]>max)
            {
                max=nums[i];
                index=i;
            }
        TreeNode* root;
        root=insertIntoBST(root,max);
        for(int i=0;i<index;++i)
            root=insertIntoBST(root,nums[i]);
        if(index!=nums.size()-1)
            for(i=index+1;i<nums.size();++i)
                root=insertIntoBST(root,nums[i]);
        return root;
    }
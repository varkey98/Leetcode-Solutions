    int rob(TreeNode* root) {
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int ret = root->val;
        if(root->left) ret += rob(root->left->left) + rob(root->left->right);
        if(root->right) ret += rob(root->right->left) + rob(root->right->right);
        return mp[root] = max(ret, rob(root->left) + rob(root->right));
    }
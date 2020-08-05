    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root)
        st.push(root);
        vector<int> ret;
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();
            ret.push_back(temp->val);
            if(temp->right!=NULL)
                st.push(temp->right);
            if(temp->left!=NULL)
                st.push(temp->left);
        }
        return ret;
        
    }
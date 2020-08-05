BSTIterator(TreeNode* root)
{
stack<TreeNode*> inOrder;
    TreeNode* temp;
    if(root)
    {
        inOrder.push(root);
        while(!inOrder.empty())
        {
           temp=inOrder.top();
           if(temp->left)
            {
                inOrder.push(temp->left);
                temp->left=NULL;
            }
            else
            {
                inOrder.pop();
                st.push(temp->val);
                if(temp->right)
                {
                    inOrder.push(temp->right);
                    temp->right=NULL;
                }
            }
        }
    }
}
    
    /** @return the next smallest number */
    int next() {
        int ret=st.front();
        st.pop();
        return ret;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
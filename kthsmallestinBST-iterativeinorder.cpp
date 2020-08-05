    int kthSmallest(TreeNode* root,int k) {
        stack<TreeNode*> inOrder;
        TreeNode* temp;
        int ret;
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
                    --k;
                    if(!k)
                        return temp->val;
                    if(temp->right)
                    {
                        inOrder.push(temp->right);
                        temp->right=NULL;
                    }
                }
            }
        }
        return ret;
    }
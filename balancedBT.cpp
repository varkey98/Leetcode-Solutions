int height(TreeNode* root,map<TreeNode*,int>& m)
    {
        if(!root)
            return -1;
        else if(m.find(root)!=m.end())
            return m[root];
        else
        {
            m[root] =max(height(root->left,m),height(root->right,m))+1;
            return m[root];
        }
        
    }
    void fun(TreeNode* root,bool* ret,map<TreeNode*,int>& m)
    {
       if(root)
        {
            if(abs(height(root->left,m)-height(root->right,m))>1)
                *ret=false;
            else
            {
                fun(root->left,ret,m);
                fun(root->right,ret,m);
            }
        }
    }
    
    bool isBalanced(TreeNode* root) {
            map<TreeNode*,int> m;

        bool ret=true;
        fun(root,&ret,m);
        return ret;
    }
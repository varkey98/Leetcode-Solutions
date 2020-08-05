void DFS(TreeNode* root,TreeNode* p1,TreeNode* p2,TreeNode* p,TreeNode* q)
{
    if(root)
    {
    path.push_back(root);
        if(root==p)
            ret.push_back(path);
        else
        {
        DFS(root->left,path,p,ret);
        DFS(root->right,path,p,ret);
        }
            
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    vector<vector<TreeNode*>> ret;
    vector<TreeNode*> temp;
    DFS(root,temp,p,ret);
    DFS(root,temp,q,ret);
    TreeNode* v=ret[0][0];
    for(int i=0;i<ret[0].size()&&i<ret[1].size();++i)
    {
        if(ret[0][i]==ret[1][i])
            v=ret[0][i];
    }
    return v;
        
}
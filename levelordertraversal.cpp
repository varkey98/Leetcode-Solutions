void Flevel(TreeNode* root,vector<vector<int>>& m,int level)
{
    if(root)
    {
    if(level<m.size())
        m[level].push_back(root->val);
    else
    {
        vector<int> temp;
        temp.push_back(root->val);
        m.push_back(temp);
    }
    Flevel(root->left,m,level+1);
    Flevel(root->right,m,level+1);
    }
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    Flevel(root,ret,0);
    return ret;
    
}
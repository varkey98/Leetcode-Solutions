map<TreeNode*,int> maxpath;
int dp(TreeNode* root)
{
  if(m.find(root)!=m.end())
    return m[root];
  if(root!=NULL)
  {
    int q=root->val;
    q=max(q+dp(root->left),q+dp(root->right));
    q=max(q,root->val);
    m[root]=q;
    return q;
  }
  else return 0;
}
int sum=INT_MIN;
void  fun(TreeNode* root)
{
  if(root)
  {
    if(dp(root->left)>0&&dp(root->right)>0)
        sum=max(sum,root->val+dp(root->left)+dp(root->right));
     else if(dp(root->left)>0)
         sum=max(sum,root->val+dp(root->left));
      else if (dp(root->right)>0)
          sum=max(sum,root->val+dp(root->right));
      else
          sum=max(sum,root->val);
    fun(root->left);
    fun(root->right);
  }
}
int maxPathSum(TreeNode* root)
{
  fun(root);
  return sum;
}

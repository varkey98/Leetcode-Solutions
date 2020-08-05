/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
       map<int,vector<TreeNode*>> m;
  bool equal(TreeNode* r1,TreeNode* r2)
  {
    if((r1&&r2)||(!r1&&!r2))
      if(r1&&r2)
        return equal(r1->right,r2->right)&&equal(r1->left,r2->left);
      else return true;
    else return false;
  }
TreeNode* clone(TreeNode* root)
{
  if(root)
  {
    TreeNode* final=child();
   final->left= clone(root->left);
   final->right= clone(root->right);
      return final;
  }
    else return NULL;
}
TreeNode* child()
{
  TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
  root->val=0;
  root->left=NULL;
  root->right=NULL;
  return root;
}
void traversal(TreeNode* root,TreeNode* temp,int target)
{
  if(temp->left)
  {
    traversal(root,temp->left,target);
    traversal(root,temp->right,target);
  }
  else
  {
    temp->left=child();
    temp->right=child();
      bool val=false;
      for(int i=0;i<m[target].size();++i)
          val=val||equal(m[target].at(i),root);
    TreeNode* final;
    final=clone(root);
      if(!val)
    m[target].push_back(final);
    temp->left=NULL;
    temp->right=NULL;
  }
}
vector<TreeNode*> makeTree(int target)
{
  if(m.find(target)==m.end())
  {
    if(target==1)
    {
      TreeNode* root=child();
      vector<TreeNode*> ret;
      ret.push_back(root);
      m[target]=ret;
    }
    else
    {
      vector<TreeNode*> temp=makeTree(target-2);
      vector<TreeNode*> ret;
      m[target]=ret;
      for(int i=0;i<temp.size();++i)
        traversal(temp[i],temp[i],target);
    }
  }
  return m[target];


}
    vector<TreeNode*> allPossibleFBT(int N) {
 if(N%2!=0)
        return makeTree(N);
        else{
            vector<TreeNode*> temp;
            return temp;
        }
    }
};
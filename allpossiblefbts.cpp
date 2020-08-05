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
void traversal(map<int,vector<TreeNode*>>& m,TreeNode* root,TreeNode* temp,int target)
{
  if(temp->left)
  {
    traversal(m,root,temp->left,target);
    traversal(m,root,temp->right,target);
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
vector<TreeNode*> makeTree(map<int,vector<TreeNode*>>&m, int target)
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
      vector<TreeNode*> temp=makeTree(m,target-2);
      vector<TreeNode*> ret;
      m[target]=ret;
      for(int i=0;i<temp.size();++i)
        traversal(m,temp[i],temp[i],target);
    }
  }
  return m[target];


}
    vector<TreeNode*> allPossibleFBT(int N) {
        map<int,vector<TreeNode*>> m;
        return makeTree(m,N);
    }
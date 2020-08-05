 #include<iostream>
#include<vector>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  vector<int> inorder(TreeNode* root,vector<int> r)
  {
  	if(root)
  	{
  		r=inorder(root->left,r);
  		r.push_back(root->val);
  		r=inorder(root->right,r);
  	}
  	return r;
  }
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
	vector<int> r1,r2,ret;
	r1=postorder(root1,r1);
	r2=postorder(root2,r2);
   
	return ret;
    }
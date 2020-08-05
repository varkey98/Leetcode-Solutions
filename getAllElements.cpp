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
    int r=max(r1.at(r1.size()-1),r2.at(r2.size()-1));
    r1.push_back(r+1);
    r2.push_back(r+1);
    int i=j=0;
    while(ret.size()<=(r1.size()+r2.size()-2))
    {
    	if(r1[i]<r2[j])
    	{
    		ret.push_back(r1[i]);
    		++i;
    	}
    	else
    	{
    		ret.push_back(r2[j]);
    		++j;
    	}
    }
	return ret;
    }
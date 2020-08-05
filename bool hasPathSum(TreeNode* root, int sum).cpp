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
  void fun(TreeNode* root,int p,int sum,bool* ret)
{
	if(root!=NULL)
	{
		p+=root->val;

		if(root->right==NULL&&root->left==NULL&&p==sum)
        {
			*ret= true;
        }
		else 
        { fun(root->left,p,sum,ret);
        fun(root->right,p,sum,ret);
        }
	}
	//else return false;
}
bool hasPathSum(TreeNode* root, int sum)
{
bool ret=false;
        fun(root,0,sum,&ret);
    return ret;
    //else return false;
}
};
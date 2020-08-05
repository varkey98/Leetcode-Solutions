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
    void child(TreeNode* root,vector<int>& ret,int k)
{
	if(root)
	{
		if(!k)
			ret.push_back(root->val);
		else 
		{
			child(root->left,ret,k-1);
			child(root->right,ret,k-1);
		}
	}
}
map<TreeNode*,TreeNode*> p;
void parent(TreeNode* root,TreeNode* temp)
{
	if(root)
	{
		p[root]=temp;
		parent(root->left,root);
		parent(root->right,root);
	}
}
void ancestor(TreeNode* root,vector<int>& ret,int k)
{
	if(root)
	{
		if(!k)
			ret.push_back(root->val);
		TreeNode* temp=p[root];
		if(temp)
		{
			if(temp->left==root)
				child(temp->right,ret,k-2);
			else
				child(temp->left,ret,k-2);
			ancestor(temp,ret,k-1);
		}
	}
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
{
	 vector<int> ret; 
    if(!K)
    {
        child(target,ret,0);
        return ret;
    }
	 child(target,ret,K);
	 parent(root,NULL);
	 ancestor(target,ret,K);
	 return ret;      
}
};
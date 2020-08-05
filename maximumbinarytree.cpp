#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 TreeNode* function(vector<int> arr, int p, int q)
 {
 	int index=p;
 	int max=arr[p];
 	if(p<=q)
 	{
 		for(int i=p;i<=q;++i)
 			if(arr[i]>max)
 			{
 				max=arr[i];
 				index=i;
 			}
 		TreeNode* root=new TreeNode(max);
 		root->left=function(arr,p,index-1);
 		root->right=function(arr,index+1,q);
 		return root;
 	}
 	else return NULL;
 }
 TreeNode* constructMaximumBinaryTree(vector<int> nums) {
 	return function(nums,0,nums.size()-1);
 }
 int main ()
 {
 	vector<int> arr;
 	arr.push_back(3);
 	arr.push_back(2);
 	arr.push_back(1);
 	arr.push_back(6);
 	arr.push_back(0);
 	arr.push_back(5);
 	TreeNode* temp=constructMaximumBinaryTree(arr);
 	cout<<temp->val;
 	return 4;
 }	
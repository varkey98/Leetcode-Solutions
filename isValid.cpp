bool isValidBST(TreeNode* root)// wont work because it doesnt check the entire subtrr but just the current node
{
	if(root)
	{
		if(root->left&&root->right!=NULL)
			if(root->left->val<root->val&&root->right->val>root->val)
				return isValidBST(root->right)&&isValidBST(root->left);
			else return false;
		else  if(root->left!=NULL)
			if(root->left->val<root->val)
				return isValidBST(root->left);
			else return false;
		else if(root->right!=NULL)
			if(root->right->val>root->val)
				return isValidBST(root->right);
			else return false;
		else return true;
	}
	else return true;               
}
void inorder(TreeNode* root,vector<int>& arr)
{
	if(root)
	{
		inorder(root->left,arr);
		arr.push_back(root->val);
		inorder(root->right,arr);
	}
}
bool isValidBST(TreeNode* root)
{
	vector<int> arr;
	inorder(root,arr);
	bool ret=true;
	for(int i=1;i<arr.size()-1;++i)
		if(arr[i-1]>=arr[i]||arr[i+1]<=arr)
			ret=false;
	return ret;
}
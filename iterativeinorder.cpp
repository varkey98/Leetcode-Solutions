vector<int> inorderTraversal(TreeNode* root)
{
	stack<TreeNode*> st;
	st.push(root);
	TreeNode* temp;
    vector<int> ret;
	while(!st.empty())
	{
		temp=st.top();
		st.pop();
		if(temp->right)
			st.push(temp->right);
		if(temp->left)
		{
			st.push(temp);
			st.push(temp->left);
		}
		else
			ret.push_back(temp->val);
	}
    return ret;
}

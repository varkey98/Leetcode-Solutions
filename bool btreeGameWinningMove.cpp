map<TreeNode*,TreeNode*> parent;
vector<TreeNode*> arr;
void dfs(TreeNode* root,TreeNode* p)
{
	if(root)
	{
		parent[root]=p;
		arr[root->val]=root;
		dfs(root->left,root);
		dfs(root->right,root);
	}
}
int bfs(queue<TreeNode*>& q,vector<int>& grey)
{
	int ret=0;
	while(!q.empty())
	{
		TreeNode* root=q.front();
		q.pop();
		++ret;
		grey[root->val]=1;
		if(root->left&&grey[root->left->val]==0)
			q.push(root->left);
		if(root->right&&grey[root->right->val]==0)
			q.push(root->right);
		if(parent[root]&&grey[parent[root]->val]==0)
			q.push(parent[root]);
	}
	return ret;
}
bool btreeGameWinningMove(TreeNode* root, int n, int x) 
{
    arr.resize(n+1);
    queue<TreeNode*> temp;
    dfs(root,NULL);
    if(parent[root])
    	temp.push(parent[root]);
    if(root->left)
    	temp.push(root->left);
    if(root->right)
    	temp.push(root->right);
    while(!temp.empty())
    {
    	TreeNode* t=temp.front();
    	temp.pop();
    	queue<TreeNode*> q;
    	q.push(root);
    	vector<int> grey(n+1,0);
    	grey[t->val]=-1;
    	int ret=bfs(q,grey);
    	if(ret<n-ret)
    		return true;
    }
    return false;
}
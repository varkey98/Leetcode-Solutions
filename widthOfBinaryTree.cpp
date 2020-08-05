int widthOfBinaryTree(TreeNode* root) //TLE O(2^h)
{
	int ret=0;
    int i=1;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
    	int size=q.size();
    	int flag=true;
    	int t1=INT_MAX,t2=INT_MIN;
    	for(int j=0;j<size;++j)
    	{
	    	TreeNode* temp=q.front();
	    	q.pop();
	    	if(temp)
	    	{
	    		t1=min(t1,i);
	    		t2=max(t2,i);
	    		q.push(temp->left);
	    		q.push(temp->right);
                if(temp->left||temp->right)
	    		    flag=false;
	    	}
	    	else
	    	{
	    		q.push(NULL);
	    		q.push(NULL);
	    	}
			++i;
    	}
        ret=max(ret,t2-t1+1);
        if(flag)
            break;	    		

    }
    return ret;
}

void dfs(TreeNode* root,unsigned long i)//O(N)
{
	if(root)
	{
		root->val=i;
		dfs(root->left,2*i);
		dfs(root->right,2*i+1);
	}
}
int widthOfBinaryTree(TreeNode* root)
{
	dfs(root,1);
	queue<TreeNode*> q;
	q.push(root);
	int ret=0;
	while(!q.empty())
	{
		int size=q.size();
		int t1=INT_MAX,t2=INT_MIN;
		for(int i=0;i<size;++i)
		{
			root=q.front();
			q.pop();
			t1=min(t1,root->val);
			t2=max(t2,root->val);
			if(root->left)
				q.push(root->left);
			if(root->right)
				q.push(root->right);
		}
		if(t1!=INT_MAX&&t2!=INT_MIN)
			ret=max(ret,t2-t1+1);
	}
	return ret;
}
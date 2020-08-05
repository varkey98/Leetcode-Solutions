struct TrieNode
{
	struct TrieNode *children[26];
	bool eow;
};
TrieNode* createNode()
{
	TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
	for(int i=0;i<26;++i)
		ret->children[i]=NULL;
	ret->eow=false;
	return ret;
}
TrieNode* insert(TrieNode* root,string key)
{
	TrieNode* temp=root;
	for(int i=0;i<key.length();++i)
	{
		int j=key[i]-'a';
		if(temp->children[j]==NULL)
			temp->children[j]=createNode();
		temp=temp->children[j];
	}
	temp->eow=true;
	return root;
}
int search(TrieNode* root,string key)
{
	TrieNode* temp=root;
	for(int i=0;i<key.length();++i)
	{
		int j=key[i]-'a';
		if(temp->children[j]==NULL)
			return -1;
		temp=temp->children[j];
	}
	if (temp!=NULL&&temp->eow)

		return 1;
	else return 0;
}
vector<vector<int>> grey;
vector<string> ret;
TrieNode* root,*inserted=createNode();
void dfs(int i,int j,string key,vector<vector<char>>& board)
{
	grey[i][j]=1;
	key.push_back(board[i][j]);
	int f=search(root,key);
	if(f==1&&search(inserted,key)!=1)
    {
        inserted=insert(inserted,key);
		ret.push_back(key);
    }
	if(f!=-1)
	{
		if(i+1<board.size()&&!grey[i+1][j])
			dfs(i+1,j,key,board);
		if(j+1<board[0].size()&&!grey[i][j+1])
			dfs(i,j+1,key,board);
		if(i>0&&!grey[i-1][j])
			dfs(i-1,j,key,board);
		if(j>0&&!grey[i][j-1])
			dfs(i,j-1,key,board);
	}
	grey[i][j]=0;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
{
    int n=board.size();
    if(n)
    {
    	root=createNode();
    	for(auto x:words)
    		root=insert(root,x);
    	int m=board[0].size();
    	grey.resize(n,vector<int>(m,0));
    	for(int i=0;i<n;++i)
    		for(int j=0;j<m;++j)
    		{
    			string key;
    			key.push_back(board[i][j]);
    			if(search(root,key)!=-1)
    				dfs(i,j,"",board);
    		}
    }
    sort(ret.begin(),ret.end());
    return ret;
}

struct TrieNode
{
    struct TrieNode *children[26];
    bool eof;
};
TrieNode* createNode()
{
    TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
    ret->eof=false;
    for(int i=0;i<26;++i)
        ret->children[i]=NULL;
    return ret;
}
void insert(TrieNode* root,string key)
{
    TrieNode* temp=root;
    for(char x:key)
    {
        if(temp->children[x-'a']==NULL)
            temp->children[x-'a']=createNode();
        temp=temp->children[x-'a'];
    }
    temp->eof=true;
}
TrieNode* search(TrieNode* root,char x)
{
    return root->children[x-'a'];
}
void find(TrieNode* root,string& key,vector<string>& ret)
{
    if(ret.size()==3)
        return ;
    else
    {
        if(root->eof)
            ret.push_back(key);
        if(ret.size()==3)
            return;
        for(int i=0;i<26;++i)
            if(root->children[i]!=NULL)
            {
                key.push_back(i+'a');
                find(root->children[i],key,ret);
                key.pop_back();
            }
    }
}
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
{
    TrieNode* root=createNode();
    for(auto key:products)
        insert(root,key);
    vector<vector<string>> ret;
    TrieNode* s=root;
    string str;
    for(char x:searchWord)
    {
        s=search(s,x);
        vector<string> temp;
        if(s!=NULL)
        {
            str.push_back(x);
            find(s,str,temp);
        }
        else
        {
            while(ret.size()!=searchWord.length())
                ret.push_back(temp);
            break;
        }
        ret.push_back(temp);
            
    }
    return ret;
}

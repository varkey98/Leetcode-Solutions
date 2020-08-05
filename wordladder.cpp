typedef struct trie
{
    struct trie *children[26];
    bool eow;
}TrieNode;
TrieNode* createNode()
{
    TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
    for(int i=0;i<26;++i)
        ret->children[i]=NULL;
    ret->eow=false;
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
    temp->eow=true;
}
bool search(TrieNode* root,string key)
{
    TrieNode* temp=root;
    for(auto x:key)
        if(temp->children[x-'a']==NULL)
            return false;
        else
            temp=temp->children[x-'a'];
        return temp!=NULL&&temp->eow;
}
int ladderLength(string b, string e, vector<string>& wordList) 
{
    TrieNode* root=createNode();
    TrieNode* grey=createNode();
    for(auto x:wordList)
        insert(root,x);
    queue<pair<string,int>> q;
    q.push({b,1});
    insert(grey,b);
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        b=p.first;
        int d=p.second;
        if(b.compare(e)==0)
            return d;
        else
        {
            string temp=b;
            for(int i=0;i<temp.length();++i)
            {
                char t=temp[i];
                for(int j='a';j<='z';++j)
                    if(j==t)
                        continue;
                    else
                    {
                        temp[i]=j;
                        if(search(root,temp)&&!search(grey,temp))
                        {
                            q.push({temp,d+1});
                            insert(grey,temp);
                        }
                    }
                temp[i]=t;
            }
        }
    }
    return 0;
}
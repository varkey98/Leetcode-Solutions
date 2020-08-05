bool isPalindrome(string a)// TLE
{
    int start=0;
    int end=a.length()-1;
    while(start<end)
        if(a[start++]!=a[end--])
            return false;
    return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) 
{
    vector<vector<int>> ret;
    for(int i=0;i<words.size();++i)
        for(int j=0;j<words.size();++j)
            if(j==i)
                continue;
            else
            {
                string a=words[i]+words[j];
                if(isPalindrome(a))
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ret.push_back(temp);
                }
            }
    return ret;
}

////////////////////////////////////////////******************************************************************************

bool isPalindrome(string a)
{
    int start=0;
    int end=a.length()-1;
    while(start<end)
        if(a[start++]!=a[end--])
            return false;
    return true;
}

struct TrieNode
{
    struct TrieNode *children[26];
    bool eow;
    int index;
};

TrieNode* createNode()
{
    TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
    ret->eow=false;
    for(int i=0;i<26;++i)
        ret->children[i]=NULL;
    ret->index=-1;
    return ret;
}

TrieNode* insert(TrieNode* root,string key,int index)
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
    temp->index=index;
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
    if(temp!=NULL&&temp->eow)
        return temp->index;
    else return -1;
}
vector<vector<int>> palindromePairs(vector<string>& words) 
{
    vector<vector<int>> ret;
    vector<int> temp;
    TrieNode* root=createNode();
    for(int i=0;i<words.size();++i)
    {
        //reverse(words[i].begin(),words[i].end());
        root=insert(root,words[i],i);
    }
    for(int i=0;i<words.size();++i)
    {
        if(words[i].length()>1)
        {
            for(int j=1;j<=words[i].length();++j)
            {
                string t=s.substr(0,j);
                reverse(t.begin(),t.end());
                int k=search(root,t);
                if(k!=-1&&k!=i)
                    if(isPalindrome(words[i]+t))
                        ret.push_back({i,k});
            }
            string t;
            for(int j=words[i].length()-1;j>=1;--j)
            {
                t.push_back(words[i][j]);
                int k=search(root,t);
                if(k!=-1&&k!=i)
                    if(isPalindrome(t+words[i]))
                        ret.push_back({k,i});
            }
        }
    }
    return ret;
}
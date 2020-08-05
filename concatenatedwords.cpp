int dfs_visit(string s,vector<string>& words)// wrong answer
{
	if(!s.length())
		return 0;
	int flag=true;
	int q=-1;
	for(auto x:words)
	{
		if(!x.length()||x.length()>s.length())
			continue;
		else if(s.substr(0,x.length()).compare(x)==0)
		{
			flag=false;
			q=max(q,dfs_visit(s.substr(x.length()),words));
            if(q>-1)
                break;
		}
	}
	if(q>-1||!flag)
		return q+1;
	else return -1;
}
vector<string> dfs(vector<string>& words)
{
	vector<string> ret;
	for(string x:words)
		if(dfs_visit(x,words)>1)
			ret.push_back(x);
	return ret;
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
    return dfs(words);
}
// java solution of trie
class trie
{
    public trie[] children;
    public boolean eof;
    public trie ()
    {
        children =new trie[26];
        for(int i=0;i<26;++i)
            children[i]=null;
        eof=false;
    }
    public void insert(trie root,String key)
    {
        trie temp=root;
        for(int i=0;i<key.length();++i)
        {   
            char x=key.charAt(i);
            if(temp.children[x-'a']==null)
                temp.children[x-'a']=new trie();
            temp=temp.children[x-'a'];
        }
        temp.eof=true;
    }
public trie search(trie root,String key)
{
	trie temp=root;
        for(int i=0;i<key.length();++i)
        {   
            char x=key.charAt(i);
            if(temp.children[x-'a']==null)
                return null;
            else temp=temp.children[x-'a'];
        }
	return temp;
}
}



class Solution {
HashMap<String,Integer> memo = new HashMap<String,Integer>();
int dfs_visit(String s,String[] words,trie root)
{
	if(s.length()==0)
		return 0;
    if(memo.containsKey(s)==true)
        return memo.get(s);
	int q=-1;
	trie temp=root;
	for(int i=0;i<s.length();++i)
	{
	    String key=new String();
		key+=s.charAt(i);
        if(temp!=null)
		    temp=root.search(temp,key);
        else break;
		if(temp!=null&&temp.eof)
			q=Math.max(q,dfs_visit(s.substring(i+1),words,root));
	}
	if(q>-1)
		q+=1;
    memo.put(s,q);
    return q;
}
List<String> dfs(String[] words,trie root)
{
	List<String> ret=new ArrayList<String>();
	for(String s: words)
		if(dfs_visit(s,words,root)>1)
			ret.add(s);
	return ret;
}

    public List<String> findAllConcatenatedWordsInADict(String[] words) {
           trie root=new trie();
    for(String x:words)
        root.insert(root,x);
    return dfs(words,root);
    }

}

///////////////

struct trie // c++ solution gives tle
{
	struct  trie *children[26];
	bool eof;
};
trie* createNode()
{
	trie* ret=(trie*)malloc(sizeof(trie));
	for(int i=0;i<26;++i)
		ret->children[i]=NULL;
	ret->eof=false;
	return ret;
}
void insert(trie* root,string key)
{
	trie* temp=root;
	for(char x:key)
	{
		if(temp->children[x-'a']==NULL)
			temp->children[x-'a']=createNode();
		temp=temp->children[x-'a'];
	}
	temp->eof=true;
}
trie* search(trie* root,string key)
{
	trie* temp=root;
	for(char x:key)
	{
		if(temp->children[x-'a']==NULL)
			return NULL;
		else temp=temp->children[x-'a'];
	}
	return temp;
}
map<string,int> memo;
int dfs_visit(string s,vector<string>& words,trie* root)
{
	if(!s.length())
		return 0;
    if(memo.find(s)!=memo.end())
        return memo[s];
	int q=-1;
	trie* temp=root;
	for(int i=0;i<s.length();++i)
	{
		string key;
		key.push_back(s[i]);
        if(temp)
		    temp=search(temp,key);
        else break;
		if(temp!=NULL&&temp->eof)
			q=max(q,dfs_visit(s.substr(i+1),words,root));
	}
	if(q>-1)
		return memo[s]=q+1;
	else return memo[s]=-1;
}
vector<string> dfs(vector<string>& words,trie* root)
{
	vector<string> ret;
	for(string s: words)
		if(dfs_visit(s,words,root)>1)
			ret.push_back(s);
	return ret;
}
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
{
    trie* root=createNode();
    for(auto x:words)
        insert(root,x);
    return dfs(words,root);
}
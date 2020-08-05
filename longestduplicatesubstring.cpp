struct TrieNode//O(N^3) algorithm, TLE.
{
	struct TrieNode *children[26];
	bool eof;
};
TrieNode* createNode()
{
	TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
	for(int i=0;i<26;++i)
		ret->children[i]=NULL;
	ret->eof=false;

	return ret;
}
TrieNode* insert(TrieNode* root,string key)
{
	TrieNode* temp=root;
	for(char x:key)
	{
		if(temp->children[x-'a']==NULL)
			temp->children[x-'a']=createNode();
		temp=temp->children[x-'a'];
	}
	temp->eof=true;
	return root;	
}
bool search(TrieNode* root,string key)
{
	TrieNode* temp=root;
	for(char x:key)
	{
		if(temp->children[x-'a']==NULL)
			return false;
		temp=temp->children[x-'a'];
	}
	return temp!=NULL&&temp->eof;
}
string longestDupSubstring(string s) 
{
	int start,end,length=0;
	TrieNode* root=createNode();
    for(int i=0;i<s.length();++i)
    {
    	string temp;
    	for(int j=i;j<s.length();++j)
    	{
    		temp.push_back(s[j]);
    		if(search(root,temp)&&(j-i+1)>length)
    		{
    			length=j-i+1;
    			start=i;
    			end=j;
    		}
    		else root=insert(root,temp);
    	}
    }
    if(length)
    	return s.substr(start,end-start+1);
    else return "";
}
///
struct TrieNode//O(N^2) algorithm, TLE. 
{
	struct TrieNode *children[26];
	bool eof;
};
TrieNode* createNode()
{
	TrieNode* ret=(TrieNode*)malloc(sizeof(TrieNode));
	for(int i=0;i<26;++i)
		ret->children[i]=NULL;
	ret->eof=false;

	return ret;
}
int insert(TrieNode* root,string key,int i)
{
	TrieNode* temp=root;
	int length=0;
	for(;i<key.length();++i)
	{
		char x=key[i];
		if(temp->children[x-'a']==NULL)
			temp->children[x-'a']=createNode();
		else
			++length;
		temp=temp->children[x-'a'];
	}
	temp->eof=true;
	return length;	
}
bool search(TrieNode* root,string key)
{
	TrieNode* temp=root;
	for(char x:key)
	{
		if(temp->children[x-'a']==NULL)
			return false;
		temp=temp->children[x-'a'];
	}
	return temp!=NULL&&temp->eof;
}
string longestDupSubstring(string s) 
{
	int start,end,length=0;
	TrieNode* root=createNode();
    for(int i=0;i<s.length();++i)
    {
    	int val==insert(root,s,i);
    	if(length<val)
    	{
    		start=i;
    		length=val;
    	}
    }
    if(length)
    	return s.substr(start,length);
    else return "";
}

// w/o trie solution using rabin karp
vector<int> power;
int rabinKarp(string& S,int m,int q)
{
	if(m>S.length()||m==0)
		return -1;
	int d=26,n=S.length();
    long int p=0;
	int h=power[m-1];
    //int h=(int)pow(26,m-1)%q;
	unordered_map<long int,vector<int>> arr;
	for(int i=0;i<m;++i)
		p=(d*p+S[i]-'a')%q;
	arr[p]={0};
	for(int s=0;s<n-m;++s)
	{
		p=(d*(p-h*(S[s]-'a'))+S[s+m]-'a')%q;
		if(arr.count(p))
		{
			for(int start:arr[p])
				if(S.substr(start,m).compare(S.substr(s+1,m))==0)
					return start;
			arr[p].push_back(s+1);
		}
		else arr[p]={s+1};
	}
	return -1;
}
string longestDupSubstring(string s)
{
    power.push_back(1);
    for(int i=1;i<=s.length();++i)
        power.push_back((26*power[i-1])%k);
	int start=0,end=s.length()-1,q;
    cout<<rabinKarp(s,800,k);
	while(start<=end)
	{
		q=start+(end-start)/2;
		int val=rabinKarp(s,q,k);
		if(val!=-1)
			if(rabinKarp(s,q+1,k)==-1)
				return s.substr(val,q);
			else start=q+1;
		else end=q-1;
	}
	return "";
}
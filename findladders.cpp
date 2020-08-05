int diff(string a,string b)
{
  int d=0;
  for(int i=0;i<a.length();++i)
    if(a[i]!=b[i])
      ++d;
  return d;
}
int minsize=INT_MAX;
unordered_map<string,bool> s;
void dfs(string b,string e,vector<string>& dictionary,vector<string>& v,vector<vector<string>>& ret)
{
  if(!b.compare(e))
  {
    if(v.size()<minsize)
    {
            ret.clear();
      ret.push_back(v);
      minsize=v.size();
    }
    else if(v.size()==minsize)
      ret.push_back(v);
  }
  else
    for(int i=0;i<dictionary.size();++i)
    {
      if(diff(b,dictionary[i])<=1&&((s.find(dictionary[i])==s.end())||!s[dictionary[i]]))
      {
        v.push_back(dictionary[i]);
        s[dictionary[i]]=true;
        dfs(dictionary[i],e,dictionary,v,ret);
        v.pop_back();
        s[dictionary[i]]=false;
      }
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
  vector<vector<string>> ret;
  vector<string> v;
 // set<string> s;
    v.push_back(beginWord);

  s[beginWord]=true;;
  dfs(beginWord,endWord,wordList,v,ret);
  return ret;
}
//another approach
map<int,int> d;
map<int,vector<int>> pi;
void bfs(string beginWord,vector<string>& dictionary)
{
  queue<int> q;
  for(int i=0;i<dictionary.size();++i)
    if(diff(beginWord,dictionary[i])<=1)
    {
      d[i]=1;
      pi[i]={-1};
      q.push(i);
    }
  while(!q.empty())
  {
    int str=q.front();
    q.pop();
    for(int i=0;i<dictionary.size();++i)
      if(diff(dictionary[str],dictionary[i])<=1&&(d.find(i)==d.end()||d[i]==d[str]+1))
      {
        if(d.find(i)==d.end())
        {
          d[i]=d[str]+1;
          vector<int> v;
          v.push_back(str);
          pi[i]=v;
          q.push(i);

        }
        else
          pi[i].push_back(str);
      }
  }
}
void dfs(int i,vector<vector<string>>& ret,string beginWord,vector<string> v,vector<string> dictionary)
{
  if(i==-1)
  {
    v.push_back(beginWord);
    ret.push_back(v);
  }
  else
  {
    v.push_back(dictionary[i]);
    vector<int> parents=pi[i];
    for(int j=0;j<parent.size();++j)
      dfs(parents[j],ret,beginWord,v,dictionary);
  }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& dictionary)
{
  vector<vector<string>> ret;
  vector<string> v;
  int i=INT_MAX;
  for(i=0;i<dictionary.size();++i)
    if(!endWord.compare(dictionary[i]))
      break;
  if(i>=dictionary.size())
    return ret;
  bfs(beginWord,dictionary);
  dfs(i,ret,beginWord,v,dictionary);
  for(i=0;i<ret.size();++i)
    reverse(ret[i].begin(),ret[i].end());
  return ret;
}
//even this approach will take a lot of time because of the bfs which takes O(stringlength*dictionary.size()) for finding neighbors.
//so we make an algorithm which takes O(stringlength*26) for finding neighbors.
map<string,int> d;
map<string,vector<string>> pi;
void bfs(string beginWord,unordered_set<string>& dictionary)
{
  queue<string> q;
  d[beginWord]=0;
  q.push(beginWord);
  while(!q.empty())
  {
    string str=q.front();
    q.pop();
    for(int i=0;i<str.length();++i)
    {
        string next=str;
        char t=next[i];
        for(int j='a';j<='z';++j)
        {
            next[i]=j;
            if(dictionary.find(next)!=dictionary.end()&&(d.find(next)==d.end()||d[next]==d[str]+1))
              {
                  if(d.find(next)==d.end())
                  {
                    d[next]=d[str]+1;
                    vector<string> v;
                    v.push_back(str);
                    pi[next]=v;
                    q.push(next);
                  }
                  else
                    pi[next].push_back(str);

                }
        }
        next[i]=t;
    }
  }
}
void dfs(string beginWord,string endWord,vector<string> v,vector<vector<string>>& ret)
{
    if(!beginWord.compare(endWord))
    {
        v.push_back(beginWord);
        ret.push_back(v);
    }
    else
    {
        v.push_back(endWord);
        vector<string> parents=pi[endWord];
        for(int i=0;i<parents.size();++i)
            dfs(beginWord,parents[i],v,ret);
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
  vector<vector<string>> ret;
  vector<string> v;
  unordered_set<string> dictionary(wordList.begin(),wordList.end());
  bfs(beginWord,dictionary);
  dfs(beginWord,endWord,v,ret);
  for(int i=0;i<ret.size();++i)
    reverse(ret[i].begin(),ret[i].end());
  return ret;
}

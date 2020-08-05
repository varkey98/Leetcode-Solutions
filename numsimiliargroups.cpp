map<string,int> parent;
bool nos_unequal(string a,string b)
{
  int ret=0;
  for(int i=0;i<a.length();++i)
    if(a[i]!=b[i])
      ret++;
  if(ret<=2)
    return true;
  else return false;
}
int find(int i)
{
  if(parent[i]==-1)
    return i;
  else return find(parent[i]);
}
bool union(int i,int j)
{
  int ip=find(i);
  int jp=find(j);
  if(ip!=jp)
  {
    parent[jp]=ip;
    return true;
  }
  else return false;
}
int numSimilarGroups(vector<string>& A)
{
  for(int i=0;i<A.size();++i)
    parent[string]=-1;
  int n=A.size();
  for(int i=0;i<A.size();++i)
    for(int j=i+1;j<A.size();++j)
      if(uni(i,j))
        --n;
  return n;
}

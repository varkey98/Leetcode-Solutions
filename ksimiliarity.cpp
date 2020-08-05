map<string,int> r;
int dp(string A,string B,int i)
{
  if(i==A.length())
    return 0;
  else if(r.find(A)!=r.end())
    return r[A];
  else if(A[i]==B[i])
  {
    r[A]=dp(A,B,i+1);
  }
  else
  {
    int j;
    int q=INT_MAX;
    for(j=i+1;j<A.length();++j)
      if(A[j]==B[i])
      {
        string buff=A;
        swap(buff[j],buff[i]);
        q=min(q,1+dp(buff,B,i+1));
      }
    r[A]=q;
  }
    return r[A];
}
int kSimilarity(string A,string B)
{
  return dp(A,B,0);
}
// another dp solution
int kSimilarity(string A, string B)
{
  if(A.length()==0)
    return 0;
  int i=0;
  while(A[i]==B[i])
    ++i;
  vector<int> matches;
  int q=i<A.length()?INT_MAX:0;
  for(int j=i+1;j<A.length();++j)
    if(A[j]!=B[i])
    continue;
    else if(B[j]==A[i])
    {
      swap(A[i],A[j]);
      return 1+kSimilarity(A.substr(i+1),B.substr(i+1));
    }
    else
      matches.push_back(j);
    for(int x:matches)
    {
      swap(A[i],A[x]);
      q=min(q,1+kSimilarity(A.substr(i+1),B.substr(i+1)));
      swap(A[i],A[x]);
    }
    return q;
}

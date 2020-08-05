map<int,int> r;
int dp(int src,int dst,vector<vector<int>>& flights,int k)
{
  --k;
  if(k>=0)
  {
    if(dst==src)
      return 0;
    else if(r.find(dst)!=r.end())
      return r[dst];
    else
    {
      int q=INT_MAX;
      for(int i=0;i<flights.size();++i)
        if(flights[i][1]==dst)
        {
          int p=-2;
          p=dp(src,flights[i][0],flights,k);
          if(p<0)
            continue;
          else
          q=min(q,p+flights[i][2]);
        }
      if(q==INT_MAX)
        return -1;
    //  r[dst]=q; cant memoize because the stored value of retex might  be lowest cost through
      return q;//some intermediate vertices even if it cant go through any more intermediate vertices.
    }
  }
  else return -1;
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    return dp(src,dst,flights,k+2);
}

//BFS algorithm
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    queue<vector<int>> q;
    vector<int> v;
    v.push_back(src);
    v.push_back(0);
    v.push_back(0);
    q.push(v);
    int p=INT_MAX;
    vector<int> s(n,10000);
    s[src]=0;
    while(!q.empty())
    {
      v=q.front();
      q.pop();
      for(int i=0;i<flights.size();++i)
        if(flights[i][0]==v[0])
          if(flights[i][1]==dst)
            p=min(p,v[1]+flights[i]);
          else if(v[2]+1<=K&&s[flights[i][1]]>v[1]+flights[i][2])
          {
          vector<int> temp;
          temp.push_back(flights[i][1]);
          temp.push_back(v[1]+flights[i][2]);
          temp.push_back(v[2]+1);
          s[flights[i][1]]=temp[1];
          q.push(temp);
          }
    }
    if(p<INT_MAX)
      return p;
    else return -1;
}

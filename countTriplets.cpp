  int countTriplets(vector<int>& arr) {
      vector<int> xr(arr.size(),0);
      xr[arr.size()-1]=arr[arr.size()-1];
      int ret=0;
      int v=0;
      for(int i=0;i<arr.size();++i)
      {
          v=arr[i];
          for(int j=i+1;j<arr.size();++j)
          {
              int u=0;
             for(int k=j;k<arr.size();++k)
             {
                  u=u^arr[k];
                 if(v==u)
                 {
                 //cout<<i<<j<<k<<endl;
                     ret++;
                 }
             }
              v=v^arr[j];
          }
      }
      return ret;
  }
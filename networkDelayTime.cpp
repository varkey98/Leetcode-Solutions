 int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,int> S;
        unordered_set<int> V;
        S[K]=0;
        V.insert(K);
        for(int j=0;j<N;++j)
        for(int i=0;i<times.size();++i)
            if(V.find(times[i][0])!=V.end())
                if(V.find(times[i][1])!=V.end())
                {
                    if(S[times[i][1]]>times[i][2]+S[times[i][0]])
                        S[times[i][1]]=times[i][2]+S[times[i][0]];
                }
                else
                {
                    V.insert(times[i][1]);
                    S[times[i][1]]=times[i][2]+S[times[i][0]];
                }
        int ret=-1;
        unordered_map<int,int>::iterator itr=S.begin();
        if(V.size()!=N)
            return ret;
        while(itr!=S.end())
        {
            if((itr->second>ret)&&(itr->first!=K))
                ret=itr->second;
            ++itr;
        }
        return ret;
        
        
    }
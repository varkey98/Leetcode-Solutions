 int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,int> S;
        unordered_set<int> V;
        int ret=-1;
        S[K]=0;
        V.insert(K);
        for(int j=0;j<N;++j)
        for(int i=0;i<times.size();++i)
            if(V.find(times[i][0])!=V.end())
                if(V.find(times[i][1])!=V.end())
                {
                    if(S[times[i][1]]>times[i][2]+S[times[i][0]])
                        S[times[i][1]]=times[i][2]+S[times[i][0]];
                    if(S[times[i][1]]>ret)
                        ret=S[times[i][1]];

                }
                else
                {
                    V.insert(times[i][1]);
                    S[times[i][1]]=times[i][2]+S[times[i][0]];
                    if(S[times[i][1]]>ret)
                        ret=S[times[i][1]];
                }
        if(V.size()!=N)
            return ret;
        return ret;       
    }
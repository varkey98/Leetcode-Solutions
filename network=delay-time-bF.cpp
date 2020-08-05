class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<int,vector<int>,greater<int>> q;
        unordered_map<int,int> m;
        m[K]=0;
        priority_queue<int> time;
        time.push(0);
        for(int i=0;i<N;++i)
            for(int j=0;j<times.size();++j)
            {
                if(m.count(times[j][0]))
                    if(m.count(times[j][1]))
                    {
                        if(m[times[j][1]]>m[times[j][0]]+times[j][2])
                            m[times[j][1]]=m[times[j][0]]+times[j][2];
                    }
                    else
                    {
                        m[times[j][1]]=m[times[j][0]]+times[j][2];
                    }
            }
        if(m.size()<N)
            return -1;
        else
        {
            int ret=-1;
            for(unordered_map<int,int>::iterator itr=m.begin();itr!=m.end();++itr)
                if(ret<itr->second)
                    ret=itr->second;
            return ret;
        }
            
    }
}; 
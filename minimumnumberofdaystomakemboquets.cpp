class Solution {
public:
    bool canMake(int day,vector<int>& bloomDay,int m,int k)
    {
        if(day<0)
            return false;
        int start=0,end=0;
        while(m&&start<bloomDay.size())
        {
            for(;start<bloomDay.size();++start)
                if(bloomDay[start]<=day)
                    break;
            end=start+1;
            bool flag=false;
            for(end=start+1;end-start<k;++end)
                if(end>=bloomDay.size()||bloomDay[end]>day)
                {
                    flag=true;
                    break;
                }
           if(!flag)
               --m;
            start=end;
        }
        return !m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if(bloomDay.size()<m*k)
            return -1;
        int start=INT_MAX,end=0,q=-1;
        for(int i=0;i<bloomDay.size();++i)
        {
            start=min(start,bloomDay[i]);
            end=max(end,bloomDay[i]);
        }
        while(start<=end)
        {
            q=start+(end-start)/2;
            if(canMake(q,bloomDay,m,k))
            {
                if(canMake(q-1,bloomDay,m,k))
                    end=q-1;
                else
                    break;
            }
            else start=q+1;
        }
        return q;
    }
};
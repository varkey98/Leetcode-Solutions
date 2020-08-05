bool judgePoint24(vector<int>& nums) 
{
    map<int,set<float>> list;
    for(int i=0;i<4;++i)
    {
        int mask=1<<i;
        for(int j=0;j<4;++j)
        {
            if(i==j)
                continue;
            int t=mask|1<<j;
            set<float> temp;
            temp.insert(nums[i]+nums[j]);
            temp.insert(nums[i]*nums[j]);
            temp.insert(nums[i]-nums[j]);
            temp.insert(nums[j]-nums[i]);
            temp.insert((float)nums[i]/nums[j]);
            temp.insert((float)nums[j]/nums[i]);
            list[t]=temp;
        }
    }
    for(int i=0;i<4;++i)
    {

        int mask=1<<i;
        for(int j=0;j<4;++j)
        {
            if(i==j)
                continue;
            int t=mask|1<<j;
            set<float> s1=list[t];
            int val=(15^t);
            set<float> s2=list[val];
            for(auto itr1=s1.begin();itr1!=s1.end();++itr1)
                for(auto itr2=s2.begin();itr2!=s2.end();++itr2)
                    {
                        float a=*itr1+*itr2;
                        float b=(*itr1)*(itr2);
                        float c=*itr1-*itr2;
                        float d=*itr2-*itr1;
                        float e=(*itr1)/(*itr2);
                        float f=(*itr2)/(*itr1);
                        if(abs(a-24.0)<1e-6||abs(b-24)<1e-6||abs(c-24)<1e-6||abs(d-24)<1e-6||abs(e-24)<1e-6||abs(f-24)<1e-6)
                            return true;
                    }

        }
    }
    return false;
}
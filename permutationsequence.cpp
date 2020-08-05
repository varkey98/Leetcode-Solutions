class Solution {
public:
    int n;
    bitset<10> mask;
    vector<int> fact;
    string fun(string val,int count,int k)
    {
        int free=n-mask.count();
        if(!free)
            return val;
        int i;
        for(i=1;i<=n;++i)
            if(!mask[i])
            {
                if(count+fact[free-1]>=k)
                    break;
                else count+=fact[free-1];
            }
        mask[i]=1;
        val.push_back(i+'0');
        return fun(val,count,k);
                
    }
    string getPermutation(int nk, int k) 
    {
        n=nk;
        fact.push_back(1);
        for(int i=1;i<=n;++i)
            fact.push_back(i*fact[i-1]);
        return fun("",0,k);
    }   
};
string ret;
int dfs(int i,int n,int k,int val,string& s,map<string,bool>& memo)
{
    if(i>=val)
    {
        ret=s;
        return 0;
    }
    else
    {
        int q=1000;
        if(i<n)
            for(int j=0;j<k;++j)
            {
                s.push_back('0'+j);
                q=min(q,dfs(i+1,n,k,val,s,memo));
                if(q==0)
                    return 0;
                s.pop_back();
            }
        else
        {
            if(i==n)
                memo[s]=true;
            string t;
            if(n>1)
                t=s.substr(i-n+1);
            for(int j=0;j<k;++j)
            {
                t.push_back(j+'0');
                if(memo.find(t)==memo.end()||memo[t]==false)
                {
                    memo[t]=true;
                    s.push_back(j+'0');
                    q=min(q,dfs(i+1,n,k,val,s,memo));
                    if(q==0)
                        return 0;
                    s.pop_back();
                    memo[t]=false;
                }
                t.pop_back();
            }
            if(i==n)
                memo[s]=false;
        }
        return q;
    }
        
}
string crackSafe(int n, int k) 
{
    int val=pow(k,n)+n-1;
    map<string,bool> memo;
    string s;
    cout<<dfs(0,n,k,val,s,memo);
    return ret;
}
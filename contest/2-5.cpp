 #include<vector>
 using namespace std;
//Q-1
 vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
{
    int q=0;
    for(int i=0;i<candies.size();++i)
        q=max(q,candies[i]);
    vector<bool> ret;
    for(int i=0;i<candies.size();++i)
        if(candies[i]+extraCandies>=q)
            ret.push_back(true);
        else ret.push_back(false);
    return ret;
}

//Q-3
bool checkIfCanBreak(string s1, string s2) 
{
    string a=s1;
    string b=s2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool x=true;
    for(int i=0;i<a.length();++i)
        if(a[i]<=b[i])
            continue;
        else x=false;
    bool y=true;
    for(int i=0;i<b.length();++i)
        if(b[i]<=a[i])
            continue;
    else  y=false;
    return x||y;      
    
}
//Q-2

int maxDiff(int num) 
{
    string s;
    vector<int> n;
    while(num)
    {
        int a=num%10;
        n.push_back(a);
        num/=10;
        
    }
    reverse(n.begin(),n.end());
    vector<int> a=n;
    int re=a[0],i;
    if(re==9)
    {
        for(i=1;i<a.size();++i)
            if(a[i]==9)
                continue;
        else break;
        if(i<a.size())
        {
            re=a[i];
            for(;i<a.size();++i)
                if(a[i]==re)
                    a[i]=9;
        }
    }
    else
        for( i=0;i<a.size();++i)
            if(a[i]==re)
                a[i]=9;
    vector<int> b=n;
    re=b[0];
    if(re==1)
    {
        for( i=1;i<b.size();++i)
            if(b[i]==0||b[i]==1)
                continue;
    else break;
    if(i<b.size())
    {
        re=b[i];
        for(;i<b.size();++i)
            if(b[i]==re)
                b[i]=0;
        }
    }
    else
        for( i=0;i<b.size();++i)
            if(b[i]==re)
                b[i]=1;
    
    int x=0,y=0;
    for( i=0;i<a.size();++i)
    {
        x=x*10+a[i];
        y=y*10+b[i];
    }
    return x-y;

    
}
//number of hats to wear, Q-4
unordered_set<string> v;
void dfs(vector<vector<int>>& hats,string s,vector<int> j,int p)
{
    if(p==hats.size())
    {
        if(v.find(s)==v.end())
            v.insert(s);
    }
    else
    {
        for(int i=0;i<hats[p].size();++i)
        {
            if(j[hats[p][i]]==0)
            {
                j[hats[p][i]]=1;
                string t=s;
                t+="|";
                t+=to_string(hats[p][i]);
                dfs(hats,t,j,p+1);
                j[hats[p][i]]=0;
            }
        }
    }
}
int numberWays(vector<vector<int>>& hats) 
{
    string s="";
    vector<int> j(40,0);
    dfs(hats,s,j,0);
    return v.size();
}

#include<vector>
#include<string>
#include<iostream>
std::vector<int> prev;
std::vector<int> next;
std::vector<int> count;
std::vector<std::vector<int>> memo;
int mint(int a,int b)

{
    return a<b?a:b;
}
int dp(int i,std::string s,int k)
{
    if(i>=s.length())
        return 0;
    if(memo[i][k]!=0)
        return memo[i][k];
    int not_taken=next[i]-i+dp(next[i],s,k),taken=101;
    if(k>0&&k>=count[i])
    {
        taken=1+dp(next[i],s,k+1-count[i]);
        int l=prev[i],r=next[i];
        if(l==-1||r==s.length()||s[l]!=s[r])
            taken=mint(taken,dp(next[i],s,k-count[i]));
        else
        {
            int val=count[l]+count[r];
            val=std::to_string(val).length();
            taken=mint(taken,l-i+val+1+dp(next[next[i]],s,k-count[i]));
        }
    }
    else if(k>0&&k<count[i]&&count[i]>9&&count[i]-k<10)
        taken=mint(taken,2+dp(next[i],s,k+10-count[i]));
    /*if(taken<not_taken)
        cout<<i<<k<<"TAKEN"<<endl;
    else cout<<i<<k<<"NOTTAKEN"<<endl;*/
    return memo[i][k]=mint(taken,not_taken);
    
}
int getLengthOfOptimalCompression(std::string s, int k) 
{
    int n=s.length();
    count.resize(n);
    char x=s[0];
    int c=1;
    std::string temp;
    for(int i=1;i<n;++i)
        if(s[i]==x)
            ++c;
        else
        {
            temp.push_back(x);
            count[temp.length()-1]=c;
            if(c>1)
                temp+=std::to_string(c);
            x=s[i];
            c=1;
        }
        temp.push_back(x);
        count[temp.length()-1]=c;
        if(c>1)
            temp+=std::to_string(c);
    prev.resize(temp.length());
    next.resize(temp.length());
    memo.resize(temp.length(),std::vector<int>(k+1));
    int l=-1,r=temp.length();
    for(int i=0;i<temp.length();++i)
        if(temp[i]>='a'&&temp[i]<='z')
        {
            prev[i]=l;
            l=i;
        }
    for(int j=temp.size()-1;j>=0;--j)
        if(temp[j]>='a'&&temp[j]<='z')
        {
            next[j]=r;
            r=j;
        }
    /*dp(0,temp,k);
    for(int i=0;i<temp.length();++i)
    {
        cout<<i<<" - ";
        for(int j=0;j<=k;++j)
            cout<<memo[i][j]<<" ";
        cout<<endl;
    }
    cout<<next[0];*/
    return dp(0,temp,k);
    return 0;
        
}
int main(int argc, char const *argv[])
{
    std::cout<<getLengthOfOptimalCompression("aabaabbcbbbaccc",6);
    return 0;
}

int dimension(int i)
{
    int ret=0;
    int n=i;
    while(i)
    {
        ++ret;
        i/=10;
    }
    return n>1?ret:0;
}
    vector<vector<vector<vector<int>>>> memo;
int dp(int i,string s,char prev,int k,int count)
{
    if(i>=s.length())
    {
        int l=dimension(count);
        return prev!='\0'?1+l:0;
    }
    if(memo[i][prev=='\0'?26:prev-'a'][k][count]!=-1)
        return memo[i][prev=='\0'?26:prev-'a'][k][count];
    int taken=0,not_taken=INT_MAX;
    if(prev=='\0'||s[i]==prev)
        taken=dp(i+1,s,s[i],k,count+1);
    else
    {
        int l=dimension(count);
        taken=1+l+dp(i+1,s,s[i],k,1);
    }
    if(k>0)
        not_taken=dp(i+1,s,prev,k-1,count);
    return memo[i][prev=='\0'?26:prev-'a'][k][count]=min(taken,not_taken);
}
int getLengthOfOptimalCompression(string s,int k)
{
    int n=s.length();
    int count=0,c=1,prev=s[0];
    for(int i=1;i<n;++i)
        if(s[i]==prev)
            ++c;
        else
        {
            count=max(count,c);
            c=1;
            prev=s[i];
        }
    memo.resize(n,vector<vector<vector<int>>>(27,vector<vector<int>>(k+1,vector<int>(n,-1))));
    return dp(0,s,'\0',k,0);
}

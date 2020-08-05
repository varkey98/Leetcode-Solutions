vector<vector<int>> memo;
bool dfs(int i, int j,int k,string& s1,string& s2,string& s3)
{
    if(i==s1.length()&&j==s2.length()&&k==s3.length())
        return true;
    else if(memo[i][j]!=-1)
        return memo[i][j];
    else
    {
        bool ret=false;
        if(i<s1.length())
            if(s1[i]==s3[k])
                ret=ret|| dfs(i+1,j,k+1,s1,s2,s3);
        if(j<s2.length())
            if(s2[j]==s3[k])
                ret=ret|| dfs(i,j+1,k+1,s1,s2,s3);
        return memo[i][j]=ret;
            
    }
}
bool isInterleave(string s1, string s2, string s3) 
{
    memo.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
    return dfs(0,0,0,s1,s2,s3);
}
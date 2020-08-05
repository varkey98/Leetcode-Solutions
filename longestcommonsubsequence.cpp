map<pair<int,int>,int> r;
int dp(string t1,string t2,int i,int j)
{
    if(i<0|j<0)
        return 0;
    else
    {
        pair<int,int> str;
       /* str+=to_string(i);
        str+="|";
        str+=to_string(j);*/
        str.first=i;
        str.second=j;
        if(r.find(str)!=r.end())
            return r[str];
        if(t1[i]==t2[j])
            r[str]= 1+dp(t1,t2,i-1,j-1);
        else
            r[str]= max(dp(t1,t2,i-1,j),dp(t1,t2,i,j-1));
        return r[str];
    }
}
int longestCommonSubsequence(string text1, string text2) {
    return dp(text1,text2,text1.length()-1,text2.length()-1);
}

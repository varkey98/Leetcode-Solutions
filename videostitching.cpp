vector<vector<int>> memo;
int dp(int i,int t,vector<vector<int>>& clips,int T)
{
    if(i>=clips.size())
    {
        if(t>=T)
            return 0;
        else return 101;
    }
    if(memo[i][t]!=-1)
        return memo[i][t];
    int not_taken=dp(i+1,t,clips,T);
    int taken=101;
    if(clips[i][0]<=t)
        taken=1+dp(i+1,max(t,clips[i][1]),clips,T);
    return memo[i][t]=min(taken,not_taken);
}
int videoStitching(vector<vector<int>>& clips, int T) 
{
    sort(clips.begin(),clips.end());
    memo.resize(clips.size(),vector<int>(100+1,-1));
    int val=dp(0,0,clips,T);
    return val<=clips.size()?val:-1;
}
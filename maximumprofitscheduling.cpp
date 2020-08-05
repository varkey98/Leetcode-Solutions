/*int dp(int i,int prev,vector<int>& start,vector<int>& end,vector<int>& profit)
{
    if(i>=start.size())
        return 0;
    int not_taken=dp(i+1,prev,start,end,profit);
    int taken=0;
    if(prev==-1||start[i]>=end[prev])
        taken=profit[i]+dp(i+1,i,start,end,profit);
    return max(taken,not_taken);
        
}*/
vector<vector<int>> memo;//O(N^2) DP
int dp(int i,int prev,vector<vector<int>>& arr)
{
    if(i>=arr.size())
        return 0;
    else if(memo[i][prev]!=-1)
        return memo[i][prev];
    int not_taken=dp(i+1,prev,arr);
    int taken=0;
    if(prev==arr.size()||arr[i][0]>=arr[prev][1])
        taken=arr[i][2]+dp(i+1,i,arr);
    return memo[i][prev]=max(taken,not_taken);
}
int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) 
{
    vector<vector<int>> arr;
    for(int i=0;i<start.size();++i)
        arr.push_back({start[i],end[i],profit[i]});
    sort(arr.begin(),arr.end());
    memo.resize(arr.size(),vector<int>(arr.size()+1,-1));
    return dp(0,arr.size(),arr);
}
///////////////////
int binarySearch(int i,vector<vector<int>>& arr)
{
    if(i>=arr.size())
        return i;
    else
    {
        int val=arr[i][1];
        bool flag=true;
        start=i+1,end=arr.size()-1,q=i;
        while(start<=end)
        {
            q=start+(end-start)/2;
            if(arr[q][0]>=val)
            {
                flag=false;
                if(q-1>0&&arr[q-1][0]>=val)
                    end=q-1;
                else break;
            }
            else start=q+1;
        }
        return flag?q:i;
    }
}
vector<int> memo;
int dp(int i,vector<vector<int>>& arr)
{
    if(i>=arr.size())
        return 0;
    else if(memo[i]!=-1)
        return memo[i];
    else
    {
        int q=arr[i][2];
        int next=binarySearch(i,arr);
        if(next<arr.size()&&next>i)
            q+=dp(next,arr);
        return memo[i]=max(q,dp(i+1));

    }
}
int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) 
{
    vector<vector<int>> arr;
    for(int i=0;i<start.size();++i)
        arr.push_back({start[i],end[i],profit[i]});
    sort(arr.begin(),arr.end());
    memo.resize(arr.size(),-1);
    return dp(0,arr);
}

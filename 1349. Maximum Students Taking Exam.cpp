vector<int> dx={0,0,1,1};
vector<int> dy={1,-1,1,-1}; //cant make  a memoisation table b/c of 64 bit mask size
int dp(long mask,long allmask,int i,vector<pair<int,int>>& list,vector<vector<int>>& arr)
{
    if(mask==allmask||i>=list.size())
        return 0;
    int not_taken=dp(mask,allmask,i+1,list,arr),taken=0;
    int x=list[i].first,y=list[i].second;
    if((mask&1<<arr[x][y])==0)
    {
        long new_mask=mask;
        int flag=0;
        vector<int> temp;
        for(int k=0;k<4;++k)
        {
            int a=x+dx[k],b=y+dy[k];
            if(a<arr.size()&&b>=0&&b<arr[0].size())
                if(arr[a][b]!=-1)
                    temp.push_back(arr[a][b]);        
        }
        new_mask|=1<<arr[x][y];
        for(auto k:temp)
            new_mask|=1<<k;
        taken=dp(new_mask,allmask,i+1,list,arr);
    }
    return max(taken,not_taken);
}
int maxStudents(vector<vector<char>>& seats) 
{
    int n=seats.size(),m=seats[0].size();
    vector<vector<int>> arr;
    vector<pair<int,int>> list;
    int count=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(seats[i][j]=='.')
                {
                    arr[i][j]=count++;
                    list.push_back({i,j});
                }
            else arr[i][j]=-1;
    long allmask=(1<<count)-1;
    return dp(0,allmask,0,list,arr);
}


//Accepted solution
vector<int> dx={0,0,1,1};
vector<int> dy={1,-1,1,-1};
vector<vector<vector<int>>> memo;
int dp(int i,int j, int mask,int pre_mask,vector<vector<char>>& arr)
{
    if(i>=arr.size())
        return 0;
    else if(memo[i][pre_mask][mask]!=-1)
        return memo[i][pre_mask][mask];
    if(j>=arr[0].size())
        return dp(i+1,0,0,mask,arr);
    else
    {
        int k=0;
        for(k=j;k<arr[0].size();++k)
            if(arr[i][k]=='.')
                break;
        if(k>=arr[0].size())
            return dp(i+1,0,0,mask,arr);
        else j=k;
        int not_taken=dp(i,j+1,mask,pre_mask,arr);
        vector<int> temp;
        for(k=0;k<4;++k)
        {
            int x=i+dx[k],y=j+dy[k];
            if(x>=0&&x<arr.size()&&y>=0&&y<arr[0].size()&&arr[x][y]=='.')
            {
                temp.push_back(k);
                arr[x][y]='#';
            }
        }
        int taken=1+dp(i,j+1,mask|1<<j,pre_mask,arr);
        for(int k:temp)
            arr[i+dx[k]][j+dy[k]]='.';
        return memo[i][pre_mask][mask]=max(taken,not_taken);
    }
}
int maxStudents(vector<vector<char>>& seats) 
{
    int allmask=(1<<seats[0].size())-1;
    memo.resize(seats.size(),vector<vector<int>>(allmask,vector<int>(allmask,-1)));
    return dp(0,0,0,0,seats);
}
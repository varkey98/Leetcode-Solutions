#define vv vector<vector<int>>
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
bool check(vv& arr)
{
    for(int i=0;i<arr.size();++i)
        for(int j=0;j<arr[0].size();++j)
            if(arr[i][j])
                return false;
    return true;
}
int minFlips(vector<vector<int>>& arr) 
{
    int n=arr.size(),m=arr[0].size();
    vv index(n,vector<int>(m));
    int count=0;
    vector<pair<int,int>> temp;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            temp.push_back({i,j});
            index[i][j]=count++;
        }
    queue<pair<vv,vv>> q;
    q.push({arr,0});
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;++i)
        {
            vv arr=q.front().first;
            int mask=q.front().second;
            q.pop();
            if(check(arr))
                return level;
            else
            {
                for(int j=0;j<count;++j)
                    if((mask&(1<<j))==0)
                    {
                        vv ne=arr;
                        int a=temp[j].first,b=temp[j].second;
                        for(int k=0;k<4;++k)
                        {
                            int x=a+dx[k],y=b+dy[k];
                            if(x>=0&&y>=0&&x<n&&y<m)
                                ne[x][y]^=1;
                        }
                        ne[a][b]^=1;
                        q.push({ne,mask|1<<j});
                    }
            }
        }
        ++level;
    }
    return -1;
}
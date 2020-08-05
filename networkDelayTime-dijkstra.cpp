int networkDelayTime(vector<vector<int>>& times, int N, int K)
{
    int* arr=(int*)calloc(N+1,sizeof(int));
    arr[K]=0;
    map<int,int> m;
    unordered_set<int> S;
    priority_queue<int,vector<int>,greater<int>> q;
    priority_queue<int> ret;
    q.push(0);
    m[0]=K;
    for(int i=0;i<N-1;++i)
    {
        int d=q.top();
        int V=m[d];
        arr[V]=d;
        ret.push(d);
        S.insert(V);
        priority_queue<int,vector<int>,greater<int>> q;
        for(int j=1;j<=N;++j)
            if(arr[j]>d+graph[V][j])
            {
                arr[j]=d+graph[V][j];
                q.push(arr[j]);
                m[arr[j]]=j;
            }
    }
    if(V.size()==N)
        return ret.top();
    else return -1;
}
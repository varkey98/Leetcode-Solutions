int shortestSubarray(vector<int>& A, int K) //O(N^2), TLE.
{
    int ret=INT_MAX;
    for(int i=0;i<A.size();++i)
    {
        int sum=0;
        for(int j=i;j<A.size();++j)
        {
            sum+=A[j];
            if(sum>=K)
            {
                ret=min(ret,j-i+1);
                break;
            }
        }
    }
    if(ret<INT_MAX)
        return ret;
    return -1;
}

int countTriplets(int* A, int ASize)
{
    int memo[65536]={0};
    int ret=0;
    for(int i=0;i<ASize;++i)
        for(int j=0;j<ASize;++j)
            memo[A[i]&A[j]]++;
    for(int i=0;i<65536;++i)
        if(memo[i]>0)
            for(int j=0;j<ASize;++j)
                if((i&A[j])==0)
                    ret+=memo[i];
    return ret;
}
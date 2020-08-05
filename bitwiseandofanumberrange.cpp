int rangeBitwiseAnd(int m, int n)
{
    if(m==0)
        return 0;
    else
    {
        int x=log2(m);
        x++;
        int k=pow(2,x)-1;
        k=k&n;
        int ret=k;
        if(m==n)
            return m;
        if(m>=k||n>k)
            return 0;
        for(int i=m;i<k;++i)
            ret=i&ret;
        return ret;
    }
}

int peakFinder(MountainArray& arr)
{
    int start=0,end=arr.length()-1;
    while(start<end)
    {
        int q=start+(end-start)/2;
        int v2=arr.get(q),v1,v3;
        if(q>0&&(v1=arr.get(q-1))>v2)
            end=q-1;
        else if(q<arr.length()-1&&(v3=arr.get(q+1))>v2)
            start=q+1;
        else if(v2>v1&&v2>v3)
            return q;       
    }
    return start;
}
int binarySearch(MountainArray& mt,int start,int end,bool isIncreasing,int target)
{
    while(start<=end)
    {
        int q=start+(end-start)/2;
        int val=mt.get(q);
        if(val==target)
            return q;
        else if(isIncreasing)
        {
            if(val<target)
                start=q+1;
            else end=q-1;
        }
        else
            if(val>target)
                start=q+1;
            else end=q-1;
    }
    return INT_MAX;
}
int findInMountainArray(int target, MountainArray &mt) 
{
    int peak=peakFinder(mt);
    int ret=min(binarySearch(mt,0,peak,true,target),binarySearch(mt,peak+1,mt.length()-1,false,target));
    return ret<INT_MAX?ret:-1;
}
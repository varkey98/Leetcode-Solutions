//O(n2) algorithm. TLE
int largestRectangleArea(vector<int>& heights) 
{
	int ret=0;
	int arr[heights.size()];
	for(int i=0;i<heights.size();++i)
	{
		int q=INT_MIN;
		int h=heights[i];
		for(int j=i;j<heights.size();++j)
		{
			h=min(h,heights[j]);
			int area=(j-i+1)*h;
			q=max(q,area);
		}
		arr[i]=q;
		ret=max(ret,arr[i]);
	}
	return ret;

}
//O(nlogn) algorithm
public int fun(int start,int end,int[] h)
{
    if(start<=end)
    {
        int q=(start+end)/2;
        int l=fun(start,q-1,h);
        int r=fun(q+1,end,h);
        int ret=Math.max(l,r);
        int ht=h[q];
        for(int i=q;i<h.length;++i)
        {
            ht=Math.min(ht,h[i]);
            ret=Math.max(ret,ht*(i-q+1));
        }
        return ret;
    }
    else return 0;
}
public int largestRectangleArea(int[] heights) {
    return fun(0,heights.length-1,heights);
}

bool fun(vector<int>& v1,vector<int>& v2)
{
	return v1[1]<v2[1];
}
int binarySearch(vector<int>& courses, int start,int time)
{
	if(start==courses.size())
		return start;
	int end=courses.size()-1;
	while(start<=end)
	{
		int q=start+(end-start)/2;
		if(t+courses[q][0]<=courses[1])
			if(q>0&&t+courses[q-1][0]<=courses[q-1][1])
				end=q-1;
			else return q;
		else start=q+1;
	}
	return courses.size();
}
vector<int> memo;
int dp(int i,vector<int>& courses)
{
	if(i>=courses.size())
		return 0;
	else if(memo[i]!=-1)
		return memo[i];
	else
	{
		int not_taken=dp(i+1,courses),taken=0;
		int next=binarySearch(courses,i+1,courses[i][0]);
		taken=1+dp(next,courses);
		return memo[i]=max(taken,not_taken);
	}
}
int scheduleCourse(vector<vector<int>>& courses) 
{
    memo.resize(courses.size(),-1);
    sort(courses.begin(),courses.end(),fun);
    return dp(0,courses);
}



class Solution {
    class sortbytime implements Comparator<int[]>
    {
        public int compare(int[] a,int[] b)
        {
            return a[1]-b[1];
        }
    }
    int [][] memo;
    int dp(int i,int t,int[][] courses)
    {
        if(i>=courses.length)
            return 0;
        else if(memo[i][t]>-1)
            return memo[i][t];
        else
        {
            int q=dp(i+1,t,courses);
            if(t+courses[i][0]<=courses[i][1])
                q=Math.max(q,1+dp(i+1,t+courses[i][0],courses));
            return memo[i][t]=q;
        }
    }
    public int scheduleCourse(int[][] courses) 
    {
        memo=new int[courses.length][10000];
        Arrays.sort(courses,new sortbytime());
        for(int[] temp:memo)
            Arrays.fill(temp,-1);
        return dp(0,0,courses);
    }
}
class Solution {
public:

int numberOfArithmeticSlices(vector<int>& arr) 
{
	int n=arr.size();
    if(n<3)
        return 0;
	int ret=0;
	vector<map<int,int>> memo(n);
	for(int i=0;i<n;++i)
		for(int j=0;j<i;++j)
		{
            if((long)arr[i] - (long)arr[j] > INT_MAX || (long)arr[i] - (long)arr[j] < INT_MIN) continue;
			int d=arr[i]-arr[j];
			memo[i][d]+=1;
			if(memo[j].count(d))
			{
				memo[i][d]+=memo[j][d];
				ret+=memo[j][d];
			}

		}
	return ret;
}
};
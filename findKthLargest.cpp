int findKthLargest(vector<int>& nums, int k) 
{
 	typedef pair<int,int> val;
 	priority_queue<val> q;
 	for(int i=0;i<nums.size();++i)
 		q.push(make_pair(nums[i],i));
 	--k;
 	while(k--)
 		q.pop();
 	return q.top().first;
}
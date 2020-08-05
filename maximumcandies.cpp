int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
    int keys_found[1000]={0};// 0 ith box is key is not found,1 ith box key is found
    vector<int> boxes(1000,0);//0 not found, 1 found but no key, 2 found and opened
    queue<int> q;
    int ret=0;
    for(int i:initialBoxes)
    {
    	if(status[i]==1)
    	{
    		q.push(i);
    		boxes[i]=2;
    	}
    	else
    		boxes[i]=1;
    }
    while(!q.empty())
    {
    	int box=q.front();
    	q.pop();
    	ret+=candies[box];
    	for(int key:keys[box])
    		if(status[key]==0&&boxes[key]!=2)
    		{
    			if(boxes[key]==1)
    			{
    				q.push(key);
    				boxes[key]=2;
    			}
    			keys_found[key]=1;
    		}
    	for(int b:containedBoxes[box])
    		if((status[b]==1||keys_found[b]==1)&&boxes[b]!=2)
    		{
    			q.push(b);
    			boxes[b]=2;
    		}
    		else boxes[b]=1;

    }
    return ret;
}
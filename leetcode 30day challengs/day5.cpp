int maxProfit(vector<int>& prices)
{
    int buy=-1,val=0,i=0;
    while(i+1<prices.size())
	    if(prices[i+1]>prices[i])
	        if(buy!=-1)
	        	i=i+1;
	        else
	        {
	        	buy=prices[i];
                i=i+1;
	        }
	    else
	    	if(buy!=-1)
            {
	    		val+=prices[i]-buy;
                buy=-1;
                i++;
            }
	    	else i=i+1;
      if(buy!=-1)
          val+=prices[i]-buy;
    return val;
}
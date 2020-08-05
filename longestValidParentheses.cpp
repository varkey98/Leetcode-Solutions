int longestValidParentheses(string s) 
{
    if(!s.length())
        return 0;
    stack<pair<int,int>> st;
    vector<int> dp(s.length(),0);
    for(int i=0;i<s.length();++i)
	    if(s[i]=='(')
	    {
            pair<int,int> temp;
            temp.first=i;
            if(i>0)
	    	    temp.second=dp[i-1];
            else temp.second=0;
	        st.push(temp);
	    }
	    else
	    	if(!st.empty())
	    	{
                pair<int,int> val=st.top();
                dp[i]+=val.second+2;
                if(i-1!=val.first)
                    dp[i]+=dp[i-1];
	    		st.pop();
	    	}
	return *max_element(dp.begin(),dp.end());           
        
}
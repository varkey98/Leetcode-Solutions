string minWindow(string s, string t) 
{
    int slow=0,fast=0;
    map<char,int> dict;
    map<char,int> arr;
    for(char x:t)
    {
        dict[x]++;
        arr[x]=0;
    }
    int i,j,length=INT_MAX;
    int c=0;
    while(fast<s.length())
    {
        while(c<t.length()&&fast<s.length())
        {
        	if(dict.find(s[fast])!=dict.end())
            {
                if(arr[s[fast]]<dict[s[fast]])
                    c++;
        		arr[s[fast]]++;
            }
        	fast++;            
        }
        if(c==t.length())
        {
        	while(c==t.length())
        	{
        		if(fast-slow<length)
        		{
        			length=fast-slow;
        			i=slow;
        			j=fast-1;
        		}
        		if(dict.find(s[slow])!=dict.end())
                {
                    //cout<<s[slow]<<" "<<slow<<" "<<fast<<" "<<c<<" "<<arr['B']<<" "<<arr['C']<<endl;
        			arr[s[slow]]--;
                    if(arr[s[slow]]<dict[s[slow]])
                        c--;
                }
        		slow++;
        	}

        }
    }
    return s.substr(i,j-i+1);
}
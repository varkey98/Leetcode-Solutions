#include<string>
using namespace std;
 int balancedStringSplit(string s) {
        string::iterator itr=s.begin();
        string::iterator itr2=s.end();
        int ret=0,c=1;itr2=itr2-1;
        while(itr!=itr2)
        {
        	if(*itr=*(itr+1))
        	{
        		c+=1;
        		if(itr!=s.end())
        		++itr;
        	}
        	else if(*itr!=*(itr+1)&&(c==1))
        	{
        		ret+=1;
        		if(itr!=s.end())
        		itr=itr+2;
        	}
        	else 
        	{
        		if(itr!=s.end())
        		itr=itr+c;
        		c=1;
        		ret+=1;
        	}

        }
        return ret;
    }
 #include<string>
using namespace std;
 int numJewelsInStones(string J, string S) {
 	int ret=0;
        string::iterator itrJ= J.begin();
        string::iterator itrS=S.begin();
        while(itrJ!=J.end())
        {
        	while(itrS!=S.end())
        	{
        		if(*itrS==*itrJ)
        			ret+=1;
        		++itrS;
        	}
        	itrS=S.begin();
        	++itrJ;
        }
        return ret;
    }
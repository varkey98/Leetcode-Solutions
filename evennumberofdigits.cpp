#include<vector>
using namespace std;
int findNumbers(vector<int>& nums) {
	vector<int>::iterator itr=nums.begin();
	int c;
	int num,ret=0;
	while(itr!=nums.end())
	{
		num=*itr;
		c=0;
		do
		        {
		        	c+=1;
		        } while (num/=10);   
		 ++itr;  
		 if(c%2==0)
		 	ret+=1;   
    }
    return ret;	
}

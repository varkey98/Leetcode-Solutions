#include<vector>
using namespace std;
#include<iostream>
#include<map>
int main ()
{
	float f=344/12;
	cout<<f;
}
 vector<int> solution(vector<int> nums, int target)
 {
 	vector<int> temp;
 	map<int,int> val; int x;
 	for(int i=0;i<nums.size();++i)
 	{
 		val[nums.at(i)]=i;
 	}
 	for(int i=0;i<nums.size();++i)
 	{
 		x=nums.at(i);
 		if(val.find(target-x)!=val.end())
 		{
            if(val.find(target-x)->second!=i)
            {
 			temp.push_back(i);
 			temp.push_back(val.find(target-x)->second);
            break;
            }
 		}
 	}
 	return temp;
 }
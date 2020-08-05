#include<iostream>
#include<vector>
#include<math.h>
vector<int> pathInZigZagTree(int label) 
{
	float k= log(label)/log(2)+1;
	int level=(int)k;        
    int max=pow(2,level)-1;
    int pos=0;
 	if(level%2==0)
 		int pos=max-label+1+pow(2,level-1)-1
}
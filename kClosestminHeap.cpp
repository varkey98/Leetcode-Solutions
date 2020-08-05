#include<vector>
using namespace std;
#include<iostream>
  int dist(vector<int> a)
  {
  	return a[0]*a[0]+a[1]*a[1];
  }
  void minHeapify(vector<vector<int>>& points, int n)
  {
  	if(n==points.size()/2)

  	{
  		if(dist(points[n-1])>dist(points[2*n-1]))
  		{
  			vector<int> temp=points[n-1];
  			points[n-1]=points[2*n-1];
  			points[2*n-1]=temp;
  		}
  	}
  	else if(n<points.size()/2)
  	{
  		if(dist(points[n-1])>dist(points[2*n-1]))
  		{
	  		vector<int> temp=points[n-1];
	  		points[n-1]=points[2*n-1];
	  		points[2*n-1]=temp;
	  		minHeapify(points,2*n);
  		}
  		else if(dist(points[n-1])>dist(points[2*n]))
  		{
	  		vector<int>  temp=points[n-1];
	  		points[n-1]=points[2*n];
	  		points[2*n]=temp;
	  		minHeapify(points,2*n+1);
  		}
  	}
  }
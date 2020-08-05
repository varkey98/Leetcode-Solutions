  #include<vector>
using namespace std;
#include<iostream>
  int dist(vector<int> a)
  {
  	return a[0]*a[0]+a[1]*a[1];
  }
void merge(vector<vector<int>>& points, int p,int q,int r)  
{
	vector<vector<int>> L,R;
	for(int i=p;i<=q;++i)
		L.push_back(points[i]);
	for(int j=q+1;j<=r;++j)
		R.push_back(points[j]);
	int i=0,j=0;
	int index=p;
	while(index<=r)
	{
		if(i==L.size())
			points[index]=R[j++];
		else if(j==R.size())
			points[index]=L[i++];
		else
		{
		if(dist(L[i])<dist(R[j]))
			points[index]=L[i++];
		else
			points[index]=R[j++];
		}
		index+=1;
	}
	//cout<<L[0][0]<<L[0][1]<<"\n"<<R[0][0]<<R[0][1];
}
void mergesort(vector<vector<int>>& points, int p, int r)
  {
  	if(p<r)
  	{
  		int q=(p+r)/2;
  		mergesort(points,p,q);
  		mergesort(points,q+1,r);
  		merge(points,p,q,r);
  	}
  }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    	vector<vector<int>> ret;
    	int i=0;
    	mergesort(points,0,points.size()-1);
    	while(K--)
     		ret.push_back(points[i++]);
    	return ret;    
    }
    int main ()
    {
    	vector<vector<int>> points;
    	vector<int> v;
    	v.push_back(0);
    	v.push_back(1);
    	points.push_back(v);
    	v.clear();
    	v.push_back(1);
    	v.push_back(0);
    	points.push_back(v);
    	mergesort(points,0,1);
    	cout<<points[0][0]<<points[0][1]<<"\n"<<points[1][0]<<points[1][1]<<"\n";
    }
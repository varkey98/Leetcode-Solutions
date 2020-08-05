#include<iostream>
#include<vector>
using namespace std;
int left(int n)
{
	return 2*n;
}
int right(int n)
{
	return 2*n+1;
}
void maxHeapify(vector<int>& arr,int i,int n)
{
	//int n=arr.size();
	if(i<=n/2)
	{
		int largest=i;
		if((left(i)<=n)&&(arr[left(i)-1]>arr[largest-1]))
			largest=left(i);
		if((right(i)<=n)&&(arr[right(i)-1]>arr[largest-1]))
			largest=right(i);
		if(largest!=i)
		{
			int temp=arr[i-1];
			arr[i-1]=arr[largest-1];
			arr[largest-1]=temp;
			maxHeapify(arr,largest,n);
		}
	}
}
void buildMaxHeap(vector<int>& arr)
{
	for(int i=arr.size()/2;i>=1;--i)
		maxHeapify(arr,i,arr.size());
}
void heapSort(vector<int>& arr)
{
	int temp;
	for(int i=arr.size();i>=2;--i)
	{
		temp=arr[i-1];
		arr[i-1]=arr[0];
		arr[0]=temp;
		maxHeapify(arr,1,i-1);
	}
}
int main ()
{
	vector<int> arr={1,10,15,8,4,25,3,5,50};
	buildMaxHeap(arr);
	heapSort(arr);
	for(int i=0;i<9;++i)
		cout<<arr[i]<<" ";
	cout<<"\n";

}
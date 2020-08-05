#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
#include<map>
struct node
{
	int val;
	int count;
};
map<int,int> m;
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}
int parent(int i)
{
	return i/2;
}
void maxHeapify(vector<node*>& arr,int i,int n)
{
	if(i<=n/2)
	{
		int largest=i;
		if((left(i)<=n)&&(arr[left(i)-1]->count>arr[largest-1]->count))
			largest=left(i);
		if((right(i)<=n)&&(arr[right(i)-1]->count>arr[largest-1]->count))
			largest=right(i);
		if(largest!=i)
		{
			struct node* temp;
			temp=arr[i-1];
			m[arr[i-1]->val]=largest;
			m[arr[largest-1]->val]=i;
			arr[i-1]=arr[largest-1];
			arr[largest-1]=temp;
			maxHeapify(arr,largest,n);
		}
	}
}
void buildMaxHeap(vector<node*>& arr)
{
	int n=arr.size();
	for(int i=n/2;i>=1;--i)
		maxHeapify(arr,i,n);
}
void heapIncreaseKey(vector<node*>& arr,int i,int k)
{
	arr[i-1]->count+=k;
	while(i>1&&(arr[parent(i)-1]->count<arr[i-1]->count))
	{
		struct node* temp=arr[parent(i)-1];
		m[arr[i-1]->val]=parent(i);
		m[arr[parent(i)-1]->val]=i;
		arr[parent(i)-1]=arr[i-1];
		arr[i-1]=temp;
		i=parent(i);
	}
}
int heapExtractMax(vector<node*>& arr)
{
	int ret=arr[0]->val;
	int n=arr.size();
	arr[0]=arr[n-1];
	arr.pop_back();
	maxHeapify(arr,1,n-1);
	return ret;
}
vector<int> topKFrequent(vector<int>& nums, int k) 
{
	vector<node*> arr;
	vector<int> ret;
	int loc=1;
	int c=0;
	for(int i=0;i<nums.size();++i)
		if(m.find(nums[i])==m.end())
		{
			struct node* temp=(struct node*)calloc(1,sizeof(struct node));
			temp->val=nums[i];
			temp->count=1;
			arr.push_back(temp);
			m[nums[i]]=loc;
			++loc;
		}
		else
			heapIncreaseKey(arr,m[nums[i]],1);
	while(k--)
		ret.push_back(heapExtractMax(arr));
	return ret;
}
int main(int argc, char const *argv[])
{
	vector<node*> arr;
	vector<int> val = {1,1,1,2,2,2,3,3,3};
	vector<int> temp=topKFrequent(val,3);
	for(int i=0;i<temp.size();++i)
		cout<<temp[i]<<" ";
	return 0;
}
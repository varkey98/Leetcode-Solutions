#include<map>
#include<vector>
#include<iostream>

using namespace std;
struct node{
	int val;
	struct node* next;
};

    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    	cout<<1;
       vector<vector<int>> ret;
       map<int,struct node*> m;
        /*int i=0;*/ int val=0;
        struct node* temp;
      //  struct  node* temp1;
        cout<<1;
        for(int i=0;i<groupSizes.size();++i)
        {
        	if(m.find(groupSizes.at(i))==m.end())
        	{
        		cout<<1;
        		temp=(node*)calloc(1,sizeof(node));
        		temp->val=i;
        		temp->next=NULL;
        		//cout<<temp->val;
        		m[groupSizes.at(i)]=temp;
        	}
        	else
        	{
        		cout<<1;
        		temp=m[groupSizes.at(i)];
        		while(temp->next!=NULL)
        			temp=temp->next;
        		temp->next=(node*)calloc(1,sizeof(node));
        		//temp1=(node*)calloc(1,sizeof(node));
        		temp=temp->next;
        		temp->val=i;
        		temp->next=NULL;
        		//temp->next=temp1;
        	}
        }
        map<int,struct node*>::iterator itr=m.begin();
        vector<int> t;
        while(itr!=m.end())

        {
        	temp=itr->second;
        	while(temp!=NULL)
        	{
        		t.push_back(temp->val);
        		temp=temp->next;
        		++val;
        		if(val>=itr->first)
        		{
        			ret.push_back(t);
        			t.clear();
        			val=0;
        		}
        	}
        	++itr;
        	if(!t.empty())
        		ret.push_back(t);
        	val=0;
        }
        return ret;
    }

int main()
{
	vector<vector<int>> v;
	int arr[]={1};
	vector<int> temp;
	for(int i=0;i<1;++i)
		temp.push_back(arr[i]);
	cout<<1;
	v=groupThePeople(temp);
	return 0;
}
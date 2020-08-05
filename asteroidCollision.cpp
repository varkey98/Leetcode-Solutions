#include<map>
#include<iostream>
#include<vector>
using namespace std;
     typedef struct List
{
	int val;
	struct List* next;
	struct List* prev;
}list;
struct LinkedList
{
	list* head;
	list* tail;
};
void insert(struct LinkedList* l1,int val)
{
	list* temp=(list*)calloc(1,sizeof(list));
	temp->val=val;
	temp->prev=NULL;
	temp->next=NULL;
	if(!l1->head)
	{
		l1->head=temp;
		l1->tail=l1->head;
	}
	else
	{
		temp->prev=l1->tail;
		l1->tail->next=temp;
		l1->tail=temp;
	}
}
void remove(LinkedList* ls,list* ptr)
{
	if(ptr==ls->head)
	{
		ls->head=ptr->next;
		if(ptr->next)
		ptr->next->prev=NULL;
	}
	else
	{
        if(ptr->prev)
		    ptr->prev->next=ptr->next;
        if(ptr->next)
		    ptr->next->prev=ptr->prev;
	}
  //  free(ptr);
}
vector<int> asteroidCollision(vector<int>& asteroids)
{
	//map<int,list*> mp;
	int start=0;
	while(start<asteroids.size()&&asteroids[start]<0)
		++start;
	struct LinkedList* l1=(struct LinkedList*)calloc(1,sizeof(LinkedList));
	l1->head=NULL;
	l1->tail=NULL;
	for(int i=start;i<asteroids.size();++i)
		insert(l1,asteroids.at(i));
	list* temp=l1->head;
	while(temp!=NULL)
	{
		//cout<<temp->val<<"\n";
		if(temp->val<0)
		{
			if(temp==l1->head||(temp->prev->val<0))
				temp=temp->next;
			else if(abs(temp->prev->val)>abs(temp->val))
			{
				temp=temp->prev;
				remove(l1,temp->next);
			}
			else if(abs(temp->val)>abs(temp->prev->val))
				remove(l1,temp->prev);
			else
			{
                temp=temp->prev;
				remove(l1,temp->next);
				remove(l1,temp);
			}
		}
		else
			temp=temp->next;
	}
	vector<int> ret;
	for(int j=0;j<start&&j<asteroids.size();++j)
		ret.push_back(asteroids[j]);
	temp=l1->head;
	while(temp!=NULL)
	{
		cout<<temp->val<<"\n";
		ret.push_back(temp->val);
		temp=temp->next;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	vector<int> asteroids={5,-15};
	vector<int> ret=asteroidCollision(asteroids);
	cout<<ret.size();
	return 0;
}
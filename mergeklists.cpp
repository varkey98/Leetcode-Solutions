/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* l1,ListNode* l2)
{
	ListNode* ret;
	ListNode* head;

	if(l1&&l2)
	{
		if(l1->val<l2->val)
		{
			ret=l1;
			l1=l1->next;
		}
		else
		{
			ret=l2;
			l2=l2->next;
		}
	}
    else if(l1)
    {
        ret=l1;
        l1=l1->next;
    }
    else if(l2)
    {
        ret=l2;
        l2=l2->next;
    }
    else return NULL;
	head=ret;
	while(l1&&l2)
	{
		if(l1->val<l2->val)
		{
			ret->next=l1;
			l1=l1->next;
		}
		else
		{
			ret->next=l2;
			l2=l2->next;
		}
		ret=ret->next;
	}
	while(l1)
	{
		ret->next=l1;
		ret=ret->next;
		l1=l1->next;
	}
	while(l2)
	{
		ret->next=l2;
		ret=ret->next;
		l2=l2->next;
	}
	return head;
}
ListNode* mergeKLists(vector<ListNode*>& lists)

{
	int n=0;
	int k=0;
    if(!lists.size())
        return NULL;
    ListNode *arr[lists.size()];
	for(int i=0;i<lists.size();++i)
	{
    	ListNode* temp=lists[i];
    	if(temp)
    	{
    		arr[k]=temp;
    		++k;
    	}
    	else continue;
    	while(temp!=NULL)
    	{
        	++n;
        	temp=temp->next;
    	}
	}
    cout<<k;
	for(int i=1;i<n;i*=2)
	{
		for(int j=0;j+i<k;j+=2*i)
			arr[j]=merge(arr[j],arr[j+i]);
	}
    if(k)
	return arr[0];
    else return NULL;
}
};
#include<stdlib.h>
#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
	ListNode* insert(ListNode* ptr,int key)
	{
		ptr=new ListNode(key);
		return ptr;
	}
ListNode* add(ListNode* l1,ListNode* l2,int c)
{
	int temp=0;
	ListNode* carry;
	if(l1&&l2)
	{
		temp=l1->val+l2->val+c;
		c=temp/10;
		carry = insert(carry,temp%10);
		carry->next=add(l1->next,l2->next,c);
		return carry;
	}
	else if(l1&&!l2)
	{
		temp=l1->val+c;
		carry = insert(carry,temp%10);
		c=temp/10;
		carry->next=add(l1->next,l2,c);
		return carry;
	}
	else if(!l1&&l2)
	{
		temp=l2->val+c;
		carry=insert(carry,temp%10);
		c=temp/10;
		carry->next=add(l1,l2->next,c);
		return carry;
	}
	else
	{
		if (c>0)
		{
			carry=insert(carry,c);
			return carry;
		}
		else return NULL;
	}
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* carry;
		 carry=add(l1,l2,0);
        return carry;

	    }
	    int main(int argc, char const *argv[])
	    {
	    	/* code */
	    	return 0;
	    }
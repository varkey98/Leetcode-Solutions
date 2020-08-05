
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
		ListNode* insert(ListNode* ptr,int key)
	{
		ListNode* temp=new ListNode(key);
		temp->next=ptr;
		return temp;
	}
ListNode* add(ListNode* l1,ListNode* l2)
{
	int temp=0;
	ListNode* carry;
	if(l1->next&&l2->next)
	{
		carry = add(l1->next,l2->next);
		temp=carry->val+l1->val+l2->val;
		carry->val=temp%10;
		temp/=10;
		carry=insert(carry,temp);
		return carry;
	}
	else if(l1->next&&!l2->next)
	{
		carry = add(l1->next,l2);
		temp=l1->val+carry->val;
		carry->val=temp%10;
		temp/=10;
		carry=insert(carry,temp);
		return carry;
	}
	else if(!l1->next&&l2->next)
	{
		carry = add(l1,l2->next);
		temp=l2->val+carry->val;
		carry->val=temp%10;
		temp/=10;
		carry=insert(carry,temp);
		return carry;
	}
	else
	{
		temp=(l1->val+l2->val);
		carry=insert(carry,temp%10);
		temp/=10;
		carry=insert(carry,temp);
		return carry;
	}
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* carry;
		 carry=add(l1,l2);
		if(carry->val==0)
			carry=carry->next;
		return carry;
	    }
};
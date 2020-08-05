struct ListNode {
     int val;
     ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
 };
 #include<iostream>
    int getDecimalValue(ListNode* head) {
    	int ret=0;
    	while(head!=NULL)
    	{
    		ret=ret*2+head->val;
    		head=head->next;
    	}
      return ret;  
    }
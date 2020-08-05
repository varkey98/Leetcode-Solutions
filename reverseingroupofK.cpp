ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode* ret=head;
    ListNode* aux;
    int c=0;
    bool flag=true;
    stack<ListNode*> arr;
    while(head!=NULL)
    {
    	++c;
    	if(c!=k)
    	{
    		arr.push(head);
    		head=head->next;
    	}
    	else
    	{
    		c=0;
    		if(flag)
    		{
    			ret=head;
    			flag=false;
    		}
    		else
    			aux->next=head;
    		ListNode* temp=head->next;
    		while(!arr.empty())
    		{
    			head->next=arr.top();
    			arr.pop();
    			head=head->next;
    		}
    		head->next=temp;
    		aux=head;
    		head=head->next;
    	}

    }
    return ret;
    
}
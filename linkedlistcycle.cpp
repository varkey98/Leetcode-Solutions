   /* ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head!=NULL&&s.find(head)==s.end())
        {
            s.insert(head);
            head=head->next;
        }
        return head;
        
    }*/
ListNode* detectCycle(ListNode* head)
{
	ListNode *tort=head,*hare;
	if(head)
		hare=head->next;
	while(hare!=NULL&&tort<hare)
	{
		tort=tort->next;
		hare=hare->next;
	}
	return hare;
}
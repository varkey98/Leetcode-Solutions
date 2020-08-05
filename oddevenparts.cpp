ListNode* oddEvenList(ListNode* head) 
{
    ListNode* h1;
    ListNode* h2;
    h1=head;
    if(!head)
        return NULL;
    if(head->next)
        h2=head->next;
    else return head;
    ListNode *t1=h1,*t2=h2;
    int n=2;
    while (true)            
    {
        if(n%2==0)
        {
            t1->next=t2->next;
            if(t1->next)
                t1=t1->next;
            else break;    
        }
        else
        {
            t2->next=t1->next;
            if(t2->next)
                t2=t2->next;
            else break;
        }
        ++n;
    }
    t1->next=h2;
    return h1;
}
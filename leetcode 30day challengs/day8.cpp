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
    ListNode* middleNode(ListNode* head) {
        ListNode *h,*t;
        h=t=head;
        while(h&&h->next)
        {
            t=t->next;
            h=h->next->next;
        }
        return t;
    }
};
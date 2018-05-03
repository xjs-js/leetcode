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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL)          return l2;
        else if (l2 == NULL)          return l1;
        else {  /*l1 != NULL  && l2 != NULL */
            ListNode *relt = NULL, *r = NULL;
            ListNode *p = l1, *q = l2;

            while (p != NULL && q != NULL) {
                if (p->val <= q->val) {
                    if (relt == NULL) {r = relt = p;}
                    else              {r->next = p; r = r->next;}
                    p = p->next;
                } else {
                    if (relt == NULL) {r = relt = q;}
                    else              {r->next = q; r = r->next;}
                    q = q -> next;
                }
            }
            while (p != NULL) {r->next = p; p = p->next; r = r->next; }
            while (q != NULL) {r->next = q; q = q->next; r = r->next; }

            return relt;
        }
    }

    /* Improved Solutions */
    /* wtf... this code looks elegent, but slower that the above*/
    /* the above is 13ms, and this is 14ms */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode *p = l1, *q = l2, *r = &head;

        while (p != NULL && q != NULL) {
            if (p->val <= q->val) {
                r->next = p; 
                p = p->next;
            } else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
            
        r->next = p ? p : q;
        return head.next;
    }



    
};

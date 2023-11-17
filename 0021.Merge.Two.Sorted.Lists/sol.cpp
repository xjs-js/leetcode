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

// 2023-11-17 Fri. 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* relt = nullptr;
        ListNode* p3 = nullptr;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 && p2) {
                // get smaller
                ListNode* smaller = nullptr;
                if (p1->val < p2->val) {
                    smaller = p1;
                    p1 = p1->next;
                } else {
                    smaller = p2;
                    p2 = p2->next;
                }

                if (relt == nullptr) {
                    relt = smaller;
                    p3 = relt;
                } else {
                    p3->next = smaller;
                    p3 = p3->next;
                }
            }
        }

        while (p1 != nullptr) {
            if (relt == nullptr) {
                p3 = relt = p1;
            } else {
                p3->next = p1;
                p3 = p3->next;
            }
            p1 = p1->next;
        }

        while (p2 != nullptr) {
            if (relt == nullptr) {
                p3 = relt = p2;
            } else {
                p3->next = p2;
                p3 = p3->next;
            }
            p2 = p2->next;
        }

        return relt;
    }
};
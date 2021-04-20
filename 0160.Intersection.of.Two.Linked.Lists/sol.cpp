/**
 * @date: 2021-04-20 Tue. 18:44
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> memo;
        
        ListNode* p = headA;
        while (p) {
            memo.insert(p);
            p = p->next;
        }
        
        p = headB;
        while (p) {
            if (memo.count(p)) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> headAMemo;
        ListNode* p = headA;
        while (p != nullptr) {
            headAMemo.insert(p);
            p = p->next;
        }

        p = headB;
        while (p != nullptr) {
            if (headAMemo.count(p)) {
                return p;
            }
            p = p->next;
        }

        return nullptr;
    }
};
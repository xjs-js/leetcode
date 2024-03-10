class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> headMemo;

        ListNode* p = head;
        while (p != nullptr) {
            if (headMemo.count(p))  return p;
            else                    headMemo.insert(p);
            p = p->next;
        }

        return nullptr;
    }
};

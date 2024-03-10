class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;

        if (head->next == nullptr) {
            return head;
        }

        ListNode* newHead = head->next;

        ListNode* p = head;
        ListNode* lastPair = nullptr;
        while (p && p->next) {
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            if (lastPair != nullptr) {
                lastPair->next = q;
            }
            lastPair = p;
            p = p->next;
        }

        return newHead;
    }
};

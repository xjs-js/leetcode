class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = head;
        while (newHead && newHead->val == val) {
            newHead = newHead->next;
        }

        if (!newHead) {
            return nullptr;
        } else {
            ListNode* prev = newHead;
            ListNode* cur = prev->next;

            while (cur) {
                if (cur->val == val) {
                    cur = cur->next;
                } else {
                    prev->next = cur;
                    prev = cur;
                    cur = prev->next;
                }
            }
            prev->next = nullptr;
            return newHead;
        }
    }
};

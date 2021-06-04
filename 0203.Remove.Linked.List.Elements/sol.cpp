class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = head;
        while (newHead && newHead->val == val) {
            ListNode* p = newHead;
            newHead = newHead->next;
            delete p;
        }

        if (!newHead) {
            return nullptr;
        } else {
            ListNode* prev = newHead;
            ListNode* cur = prev->next;

            while (cur) {
                if (cur->val == val) {
                    ListNode* p = cur;
                    cur = cur->next;
                    delete p;
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

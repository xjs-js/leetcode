/**
 * @date: 2021-04-16 16:41 Fry.
 */
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        ListNode* p = node;
        while (next) {
            p->val = next->val;
            if (next->next == nullptr) {
                p->next = nullptr;
            }
            p = next;
            next = next->next;
        }
    }
};
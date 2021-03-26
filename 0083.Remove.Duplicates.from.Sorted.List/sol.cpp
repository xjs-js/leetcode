/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /* 链表为空 */
        if (!head)
            return head;

        ListNode* cur = head;
        ListNode* next = head->next;

        while (cur) {
            while (next && next->val == cur->val) {
                next = next->next;
            }

            if (next != cur->next) {
                cur->next = next;
            }
            cur = next;
        }

        return head;
    }
};
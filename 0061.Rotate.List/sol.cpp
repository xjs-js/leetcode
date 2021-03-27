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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;

        // 计算链表中节点的数量
        int nodeNum = 1;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            ++nodeNum;
        }

        k = k % nodeNum;
        if (k == 0) {
            return head;
        } else {
            cur->next = head;
            int j = nodeNum - k;

            ListNode* prev = cur;
            cur = cur->next;    // cur = head;

            for (int i = 0; i < j; ++i) {
                prev = cur;
                cur = cur->next;
            }

            prev->next = nullptr;
            head = cur;
        }

        return head;
    }
};
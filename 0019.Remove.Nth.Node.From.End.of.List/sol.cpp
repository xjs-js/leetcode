/**
 * @date: 2021-04-16 17:01 Fry.
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return head;
        }
        
        int count = 0;
        ListNode* p = head;
        while (p) {
            ++count;
            p = p->next;
        }
        
        int frontLen = count - n;
        
        if (frontLen == 0) {
            return head->next;
        }
        
        p = head;
        while (--frontLen) {
            p = p->next;
        }
        
        if (p->next) {
            p->next = p->next->next;
        } else {
            p->next = nullptr;
        }
        
        return head;
    }
};
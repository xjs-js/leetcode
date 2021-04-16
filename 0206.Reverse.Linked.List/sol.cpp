/**
 * @date: 2021-04-16 17:30 Fry.
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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        
        
        stack<ListNode*> sk;
        sk.push(head);
        ListNode* p = head->next;
        head->next = nullptr;
        while (p) {
            sk.push(p);
            p = p->next;
        }
        
        
        ListNode* newHead = nullptr;
        if (!sk.empty()) {
            newHead = sk.top();
            p = sk.top();
            sk.pop();
            while (!sk.empty()) {
                p->next = sk.top();
                p = sk.top();
                sk.pop();
            }
        }
        
        return newHead;
        
    }
};
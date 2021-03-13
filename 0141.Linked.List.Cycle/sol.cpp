/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> exist;

        ListNode* p = head;
        while (p) {
            if (exist.count(p) == 0) {
                exist.insert(p);
                p = p->next;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
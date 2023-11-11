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
    ListNode* middleNode(ListNode* head) {
        int listLen = 0;
        ListNode* p = head;
        while (p) {
            ++listLen;
            p = p->next;
        }

        int resultIndex = listLen / 2;
        p = head;
        while (resultIndex > 0) {
            --resultIndex;
            p = p->next;
        }
        return p;
    }
};
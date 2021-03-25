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
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        
        // 先把开头的重复元素给去掉
        int headVal = head->val;
        ListNode* headNext = head->next;
        
        while (true) {
            while (headNext && headNext->val == headVal) {
                headNext = headNext->next;
            }
            if (headNext != head->next) {
                head = headNext;
                headVal = head->val;
                if (head) {
                    headNext = head->next;
                } else {
                    break;
                }
            }
            else {
                break;
            }
        }
        
        if (nullptr == headNext) {
            return head;
        }

        ListNode* prevNode = head;
        ListNode* p = headNext;
        int prevVal = p->val;

        ListNode* q = p->next;
        while (q != nullptr) {
            if (q->val == p->val) {
                q = q->next;
                while (q && q->val == p->val) {
                    q = q->next;
                }
                prevNode->next = q;
                p = q;
                if (q != nullptr) {
                    q = q->next;
                }
            } else {
                prevNode = p;
                p = q;
                q = q->next;
            }
        }

        return head;
    }
};
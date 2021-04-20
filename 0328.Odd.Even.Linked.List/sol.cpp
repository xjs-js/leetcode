/**
 * @date: 2021-04-20 18:03 Tue.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        
        // 奇偶数链的最后一个节点
        ListNode* oddLast = head;
        ListNode* evenLast = head->next;
        while (evenLast && evenLast->next) {
            ListNode* evenFirst = oddLast->next;
            ListNode* nextOdd = evenLast->next;
            oddLast->next = nextOdd;
            evenLast->next = nextOdd->next;
            nextOdd->next = evenFirst;
            // 将两个指针向后移动
            evenLast = evenLast->next;
            oddLast = oddLast->next;
        }
        
        return head;
    }
};
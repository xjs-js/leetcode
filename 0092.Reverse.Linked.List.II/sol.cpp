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
     ListNode* reverseBetween(ListNode* head, int left, int right) {
         int listLen = 0;
         ListNode* p = head;
         while (p != nullptr) {
             ++listLen;
             p = p->next;
         }
         
        if (left == right)
            return head;

         ListNode* front_prev = nullptr;
         ListNode* front = head;
         for (int i = 1; i < left; ++i) {
             front_prev = front;
             front = front->next;
         }


         ListNode* back = head;
         ListNode* back_next = nullptr;
         for (int i = 1; i < right; ++i) {
             back = back->next;
         }
         back_next = back->next;

         
         p = front;
         ListNode* q = front->next;
         ListNode* r = nullptr;
         while (q && q != back_next) {
             r = q->next;
             q->next = p;
             p = q;
             q = r;
         }

         if (front_prev)
             front_prev->next = back;
         
         front->next = back_next;

         if (left == 1) {
             head = back;
         }

         return head;
     }
 };
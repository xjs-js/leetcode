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


 /*
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLen = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++listLen;
            p = p->next;
        }
        
        int middleIndex = -1;
        if (listLen % 2 == 0) {
            middleIndex = listLen / 2;
        }
        else {
            middleIndex = (1 + listLen) / 2;
            if (k == middleIndex)
                return head;
        }

        if (k > middleIndex) {
            k = listLen + 1 - k;
        }

        ListNode* front_prev = nullptr;
        ListNode* front = head;
        for (int i = 1; i < k; ++i) {
            front_prev = front;
            front = front->next;
        }


        ListNode* back = head;
        ListNode* back_next = nullptr;
        for (int i = 1; i < listLen + 1 - k; ++i) {
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

        if (k == 1) {
            head = back;
        }

        return head;
    }
};

*/
/**
 * 
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int listLen = 0;
        ListNode* p = head;
        while (p != nullptr) {
            ++listLen;
            p = p->next;
        }
        
        int middleIndex = -1;
        if (listLen % 2 == 0) {
            middleIndex = listLen / 2;
        }
        else {
            middleIndex = (1 + listLen) / 2;
            if (k == middleIndex)
                return head;
        }

        if (k > middleIndex) {
            k = listLen + 1 - k;
        }

        ListNode* front_prev = nullptr;
        ListNode* front = head;
        ListNode* front_next = nullptr;
        for (int i = 1; i < k; ++i) {
            front_prev = front;
            front = front->next;
        }
        front_next = front->next;


        ListNode* back_prev = nullptr;
        ListNode* back = head;
        ListNode* back_next = nullptr;
        for (int i = 1; i < listLen + 1 - k; ++i) {
            back_prev = back;
            back = back->next;
        }
        back_next = back->next;

        front->next = back->next;
        if (front_prev) {
            front_prev->next = back;
        }
        else {
            head = back;
        }

        if (front_next == back) {
            back->next = front;
        } else {
            back->next = front_next;
            back_prev->next = front;
        } 

        return head;
    }
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = head;
        while (newHead && newHead->val == val) {
            ListNode* p = newHead;
            newHead = newHead->next;
            delete p;
        }

        if (!newHead) {
            return nullptr;
        } else {
            ListNode* prev = newHead;
            ListNode* cur = prev->next;

            while (cur) {
                if (cur->val == val) {
                    ListNode* p = cur;
                    cur = cur->next;
                    delete p;
                } else {
                    prev->next = cur;
                    prev = cur;
                    cur = prev->next;
                }
            }
            prev->next = nullptr;
            return newHead;
        }
    }
};

// 2024-03-08
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dumbHead = new ListNode(-1, nullptr);

        if (dumbHead == nullptr)
            return nullptr;

        ListNode* p = head;
        ListNode* newP = dumbHead;
        while (p != nullptr) {
            if (p->val != val) {
                newP->next = p;
                newP = newP->next;
                p = p->next;
            } else {
                ListNode* q = p;
                p = p->next;
                delete q;
            }
        }
        newP->next = nullptr;
        
        ListNode* relt = dumbHead->next;
        delete dumbHead;
        return relt;
    }
};
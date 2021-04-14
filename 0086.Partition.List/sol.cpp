/**
 * @date: 2021-04-14 23:37 Wen
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }
        
        vector<ListNode*> less;
        vector<ListNode*> greater;
        
        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                less.emplace_back(p);
            } else {
                greater.emplace_back(p);
            }
            p = p->next;
        }
        
        ListNode* left = new ListNode;
        p = left;
        for (int i = 0; i < less.size(); ++i) {
            p->next = less[i];
            p = p->next;
            if (i == less.size() - 1) {
                p->next = nullptr;
            }
        }
        
        ListNode* right = new ListNode;
        ListNode* q = right;
        for (int i = 0; i < greater.size(); ++i) {
            q->next = greater[i];
            q = q->next;
            if (i == greater.size()-1) {
                q->next = nullptr;
            }
        }
        
        p->next = right->next;
        return left->next;
    }
};
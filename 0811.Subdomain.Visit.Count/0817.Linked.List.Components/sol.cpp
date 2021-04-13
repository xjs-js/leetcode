/**
 * @date: 2021-04-13 18:21 Tue
 * @note: 有点像连通分量的意思
 */

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
    int numComponents(ListNode* head, vector<int>& G) {
        int count = 0;
        unordered_set gs(G.begin(), G.end());
        
        ListNode* p = head;
        while (p) {
            if (gs.count(p->val)) {
                ListNode* q = p->next;
                while (q && gs.count(q->val)) {
                    q = q->next;
                }
                p = q;
                ++count;
            } else {
                p = p->next;
            }
        }
        return count;
    }
};
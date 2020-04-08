
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // walk through to calculate the num of nodes
        ListNode* iter = head;
        int counter = 1;
        while(iter->next != NULL) {
            iter = iter->next;
            ++counter;
        }

        // return to the head position
        iter = head;
        int step = counter / 2;
        while (step-- != 0) {
            iter = iter->next;
        }

        return iter;
    }
};
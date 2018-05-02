#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode first(0);
        ListNode *current = &first;

        int carry = 0;
        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
	        int val2 = l2 ? l2->val : 0;

	        int sum = carry + val1 + val2;
	        carry = sum / 10;

	        current->next = new ListNode(sum % 10);
	        current = current->next;

	        l1 = l1 ? l1->next : NULL;
	        l2 = l2 ? l2->next : NULL;
        }
        return first.next;
    }

    void output(ListNode* l) {
        while (l) {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }

    ListNode* input(int n) {
        ListNode first(0);
        ListNode *current = &first;
		
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            current->next = new ListNode(num);
            current = current->next;
        }

        return first.next;
    }
};



int main()
{
    int m, n;
    ListNode *l1, *l2, *l3;
    Solution s;

    cin >> m >> n;
    l1 = s.input(m);
    l2 = s.input(n);
    l3 = s.addTwoNumbers(l1, l2);
	
    s.output(l3);
    return 0;
}
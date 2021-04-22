class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        
        stack<ListNode*> sk_node;   // 存放指针
        stack<int> sk_index;  // 存放下标
        unordered_map<int, int> rlt;    // <下标，值>
        
        ListNode* p = head;
        int index = 0;
        while (p) {
            if (sk_node.empty()) {  // 入栈
                sk_node.push(p);
                sk_index.push(index);
            } else {
                while (!sk_node.empty()) {
                    ListNode* top = sk_node.top();
                    if (top->val >= p->val) {
                        break;
                    } else {
                        rlt[sk_index.top()] = p->val;
                        sk_node.pop();
                        sk_index.pop();
                    }
                }
                sk_node.push(p);
                sk_index.push(index);
            }
            
            ++index;
            p = p->next;
        }
        
        vector<int> result;
        for (int i = 0; i < index; ++i) {
            result.emplace_back(rlt[i]);
        }
        return result;
    }
};
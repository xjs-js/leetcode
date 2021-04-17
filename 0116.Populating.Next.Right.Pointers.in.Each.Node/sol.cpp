/**
 * @date: 2021-04-17 14:50 Sat.
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        vector<Node*> que;
        que.push_back(root);
        
        while (!que.empty()) {
            vector<Node*> newQue;
            for (int i = 0; i < que.size(); ++i) {
                Node* cur = que[i];
                if (cur->left) {
                    newQue.push_back(cur->left);
                }
                
                if (cur->right) {
                    newQue.push_back(cur->right);
                }
                
                if (i+1 < que.size()) {
                    cur->next = que[i+1];
                }
            }
            que = newQue;
        }
        
        return root;
    }
};
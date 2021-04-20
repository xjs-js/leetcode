/**
 * @date: 2021-04-20 17:24 Tue.
 */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        queue<Node*> que;
        que.push(root);
        
        do {
            queue<Node*> newQueue;
            vector<int> inner;
            while (!que.empty()) {
                if (Node* frontNode = que.front()) {
                    vector<Node*> children = frontNode->children;
                    inner.emplace_back(frontNode->val);
                    for (int i = 0; i < children.size(); ++i) {
                        newQueue.push(children[i]);
                    }
                }
                que.pop();
            }
            que = newQueue;
            result.emplace_back(inner);
        } while (!que.empty());

        return result;
    }
};
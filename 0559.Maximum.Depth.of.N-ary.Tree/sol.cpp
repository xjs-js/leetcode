/**
 * @date: 2021-04-20 17:38 Tue.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int _maxDepth;
    
    void dfs(Node* node, int acc) {
        if (!node) {
            return ;
        }
        vector<Node*> children = node->children;
        if (children.size() == 0) {
            _maxDepth = max(_maxDepth, acc);
        } else {
            for (int i = 0; i < children.size(); ++i) {
                dfs(children[i], acc + 1);
            }
        }
    }
    
    int maxDepth(Node* root) {
        _maxDepth = 0;
        dfs(root, 1);
        return _maxDepth;
    }
};
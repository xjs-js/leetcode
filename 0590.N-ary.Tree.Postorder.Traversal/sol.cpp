/**
 * @date: 2021-04-20 17:15 Tue.
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
private:
    void postorder(Node* node, vector<int>& result) {
        if (!node) {
            return ;
        }
        
        vector<Node*>& children = node->children;
        for (int i = 0; i < children.size(); ++i) {
            postorder(children[i], result);
        }
        result.emplace_back(node->val);
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
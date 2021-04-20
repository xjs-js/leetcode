/**
 * @date: 2021-04-20 16:47
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
    void preorder(Node* node, vector<int>& result) {
        if (!node) {
            return ;
        }
        
        result.emplace_back(node->val);
        
        vector<Node*>& children = node->children;
        for (int i = 0; i < children.size(); ++i) {
            preorder(children[i], result);
        }
        
    }
public:
    
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};
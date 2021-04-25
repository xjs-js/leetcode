class Solution {
public:
    vector<TreeNode*> _nodes;
    
    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        
        if (node->left) inorder(node->left);
        _nodes.push_back(node);
        if (node->right) inorder(node->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        
        TreeNode* cur = nullptr;
        for (int i = 0; i < _nodes.size()-1; ++i) {
            cur = _nodes[i];
            cur->left = nullptr;
            cur->right = _nodes[i+1];
        }
        _nodes[_nodes.size()-1]->left = nullptr;
        _nodes[_nodes.size()-1]->right = nullptr;
        
        return _nodes[0];
    }
};
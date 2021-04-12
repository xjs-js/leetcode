/**
 * @date: 2021-04-12 16:24 Mon 
 * @name: 二叉树剪枝
 */
class Solution {
public:
    map<TreeNode*, bool> _result;
    
    bool hasOne(TreeNode* node) {
        if (node == nullptr) {    
            return false;
        }
        
        if (_result.find(node) != _result.end()) {
            return _result[node];
        }
        
        if (node->val == 1) {
            _result[node] = true;
            return true;
        }
        
        bool childResult = hasOne(node->left) || hasOne(node->right);
        _result[node] = childResult;
        return childResult;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (!hasOne(root)) {
            return nullptr;
        }
        
        if (!hasOne(root->left)) {
            root->left = nullptr;
        } else {
            pruneTree(root->left);
        }
        
        if (!hasOne(root->right)) {
            root->right = nullptr;
        } else {
            pruneTree(root->right);
        }
        
        return root;
    }
};
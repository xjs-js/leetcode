/**
 * @date: 2021-04-17 14:56 Sat.
 */

class Solution {
    vector<int> _arr;
public:
    void inOrder(TreeNode* node, int k) {
        if (!node) {
            return ;
        }
        
        if (_arr.size() >= k) return;
        
        if (node->left) inOrder(node->left, k);
    
        if (_arr.size() >= k) return;
        
        _arr.emplace_back(node->val);
        
        if (_arr.size() >= k) return;
        
        if (node->right) inOrder(node->right, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        
        return _arr[k-1];
    }
};
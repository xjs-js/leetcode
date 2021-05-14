class Solution {
private:
    TreeNode* _preNode;
public:
    void preOrder(TreeNode* node) {
        if (!node) {
            return ;
        } else {
            if (_preNode != nullptr) {
                _preNode->right = node;
            }
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            
            _preNode = node;
            if (left) {
                preOrder(left);
            }
            
            if (right) {
                preOrder(right);
            }
            
            
            node->left = nullptr;
        }
    }
    
    void flatten(TreeNode* root) {
        _preNode = nullptr;
        
        preOrder(root);
    }
};

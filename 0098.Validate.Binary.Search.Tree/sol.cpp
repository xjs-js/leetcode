/**
 * @date: 2021-04-16 15:55 Fri.
 */

/** 中序遍历是否是递增的 */
class Solution {
public:
    vector<int> arr;
    
    void inOrder(TreeNode* node) {
        if (!node) {
            return ;
        }
        
        if (node->left) {
            inOrder(node->left);
        }
        arr.emplace_back(node->val);
        if (node->right) {
            inOrder(node->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        inOrder(root);
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i-1]) {
                return false;
            }
        }
        return true;
    }
};
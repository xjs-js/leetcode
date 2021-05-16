/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* _left, _right;
    int _depthX, _depthY;
    int _parentX, _parentY;
    
    void dfs(TreeNode* root, int level, int x, int y) {
        if (!root) {
            return ;
        } else {
            if (root->left && root->left->val == x) {
                _depthX = level + 1;
                _parentX = root->val;
            } else if (root->right && root->right->val == x) {
                _depthX = level + 1;
                _parentX = root->val;
            } else if (root->left && root->left->val == y) {
                _depthY = level + 1;
                _parentY = root->val;
            } else if (root->right && root->right->val == y) {
                _depthY = level + 1;
                _parentY = root->val;
            }
            
            if (_depthX != -1 && _depthY != -1) {
                return ;
            }
            
            dfs(root->left, level + 1, x, y);
            dfs(root->right, level + 1, x, y);
        }
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        _depthX = -1;
        _depthY = -1;
        dfs(root, 0, x, y);

        return (_depthX == _depthY) && (_parentX != _parentY);
    }
};

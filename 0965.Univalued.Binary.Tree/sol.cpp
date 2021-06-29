/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool _relt;
    void dfs(TreeNode* node, int val) {
        if (!_relt) {
            return;
        } else {
            if (node->val != val) {
                _relt = false;
                return;
            } else {
                if (_relt && node->left) {
                    dfs(node->left, val);
                }
                if (_relt && node->right) {
                    dfs(node->right, val);
                }
            }
        }
    }

public:
    bool isUnivalTree(TreeNode* root) {
        _relt = true;
        if (!root){
            return false;
        }

        if (_relt && root->left) dfs(root->left, root->val);
        if (_relt && root->right) dfs(root->right, root->val);

        return _relt;
    }
};

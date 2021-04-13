/**
 * @date: 2021-04-13 21:59 Tue
 */
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
public:
    int _depth;
    
    void dfs(TreeNode* node, int acc) {
        if (!node->left && !node->right) {
            _depth = max(_depth, acc);
            return ;
        }
        
        if (node->left) {
            dfs(node->left, acc + 1);
        }
        
        if (node->right) {
            dfs(node->right, acc + 1);
        }
    }
    
    int maxDepth(TreeNode* root) {        
        if (!root)  return 0;
        
        _depth = 1;
        if (root->left) dfs(root->left, 2);
        if (root->right) dfs(root->right, 2);
        
        return _depth;
    }
};
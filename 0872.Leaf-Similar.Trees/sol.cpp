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
    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        
        if (!root->left && !root->right) arr.push_back(root->val);
        if (root->left) dfs(root->left, arr);
        if (root->right) dfs(root->right, arr);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left;
        vector<int> right;
        
        dfs(root1, left);
        dfs(root2, right);
        
        if (left.size() != right.size()) {
            return false;
        }
        
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        
        return true;
    }
};

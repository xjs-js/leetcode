/**
 * @date: 2021-04-01 17:12
 * @follow-up: 写完下楼买点东西
 */


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
private:
    uint64_t _result = 0;
public:
    void dfs(TreeNode* node, uint64_t num) {
        if (node->left == nullptr && node->right == nullptr) {
            _result += num * 10 + node->val;
        }

        if (node->left) {
            dfs(node->left, num*10 + node->val);
        }
        if (node->right) {
            dfs(node->right, num*10 + node->val);
        }
    }

    /* 递归就行了 */
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        
        if (root->left) {
            dfs(root->left, root->val);
        }
        if (root->right) {
            dfs(root->right, root->val);
        }

        return _result;
    }
};

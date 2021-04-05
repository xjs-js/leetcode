/**
 * @date: 2021-04-05 20:51
 * @note: acwing_week32
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
    void UpdateResult(int& result, int val) {
        if (result == -1) {
            result = val;
        } else {
            result = min(result, val);
        }
    }
public:
    /**
     * 用递归的方法
     * 在以下几个值中取最小值 
     *   1. minDiffInBST(root->left)
     *   2. miniDiffInBST(root->right)
     *   3. root->val - 左子树的最大值
     *   4. 右子树的最小值 - root->val
     */
    int minDiffInBST(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // 初始化结果
        int result = -1;
        // 左子树
        if (root->left) {
            // 根据二叉搜索🌲的性质找到左子树的最大值
            TreeNode* p = root->left;
            while (p && p->right) {
                p = p->right;
            }
            // 对应3.root->val - 左子树的最大值
            UpdateResult(result, root->val - p->val);

            // 确保节点数大于2
            if (root->left->left || root->left->right) {
                // 对应1. minDiffInBST(root->left)
                UpdateResult(result, minDiffInBST(root->left));
            }
        }

        if (root->right) {
            TreeNode* q = root->right;
            while (q && q->left) {
                q = q->left;
            }
            // 对应4. 右子树的最小值 - root->val
            UpdateResult(result, q->val - root->val);

            // 确保节点数大于2
            if (root->right->left || root->right->right) {
                // 对应2. miniDiffInBST(root->right)
                UpdateResult(result, minDiffInBST(root->right));
            }
        }

        return result;        
    }
};

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
    int deepestLeavesSum(TreeNode* root) {
        // root是空的
        if (!root) {
            return 0;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            queue<TreeNode*> newQue;
            int val = 0;
            while (!que.empty()) {
                TreeNode* front = que.front();
                que.pop();
                if (front->left) {
                    newQue.push(front->left);
                }
                if (front->right) {
                    newQue.push(front->right);
                }
                val += front->val;
            }

            if (newQue.size() == 0) {
                return val;
            }
            que = newQue;
        }

        return 0;
    }
};
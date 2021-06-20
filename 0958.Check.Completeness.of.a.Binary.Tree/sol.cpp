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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        vector<TreeNode*> last; // 最后一层
        while (!que.empty()) {
            int q = que.size();
            last.resize(0);
            bool isNextAllNull = true;
            bool hasCurNull = false;
            while (q--) {
                TreeNode* front = que.front();
                last.push_back(front);
                que.pop();
                if (front) {
                    que.push(front->left);
                    que.push(front->right);
                    if (front->left || front->right) {
                        isNextAllNull = false;
                    }
                } else {
                    /* 当前行有null值 */
                    hasCurNull = true;
                }
            }
            /* 当前行有null值 并且 下一行有非null值 */
            if (!isNextAllNull && hasCurNull) {
                return false;
            }

            if (isNextAllNull) {
                break;
            }
        }

        /* 检查最后一行 */
        int i = 0;
        while (i < last.size() && last[i] != nullptr) {
            ++i;
        }

        for (int j = i + 1; j < last.size(); ++j) {
            if (last[j] != nullptr) {
                return false;
            }
        }
        return true;
    }
};

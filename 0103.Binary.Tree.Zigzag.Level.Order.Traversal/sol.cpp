/**
 * @date: 2021-04-17 23:32 Sat.
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> que;
        que.push(root);
        
        vector<vector<int>> result;
        while (!que.empty()) {
            int left = que.size();
            vector<int> inner;
            while (left--) {
                TreeNode* front = que.front();
                que.pop();
                inner.emplace_back(front->val);
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);
            }
            result.emplace_back(inner);
        }
        
        for (int i = 1; i <= result.size(); ++i ) {
            if (i % 2 == 0) {
                reverse(result[i-1].begin(), result[i-1].end());
            }
        }
        
        return result;
    }
};
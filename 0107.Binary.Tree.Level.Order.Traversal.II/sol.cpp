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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> relt;

        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int q = que.size();
            vector<int> curRelt;
            while (q--) {
                if (TreeNode* front = que.front()) {
                    curRelt.push_back(front->val);
                    if (front->left) {
                        que.push(front->left);
                    }
                    if (front->right) {
                        que.push(front->right);
                    }
                }
                que.pop();
            }
            relt.push_back(curRelt);
        }
        return vector<vector<int>>(relt.rbegin(), relt.rend());
    }
};

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
    map<TreeNode*, pair<int, int>> _memo;
    map<int, vector<int>> _relt;
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        _memo.insert({root, {0, 0}});

        while (!que.empty()) {
            int s = que.size();
            map<int, vector<int>> cur;
            while (s--) {
                TreeNode* front = que.front();
                que.pop();
                auto p = _memo.at(front);
                cur[p.second].push_back(front->val);
                if (front->left) {
                    _memo.insert({front->left, {p.first+1, p.second-1}});
                    que.push(front->left);
                }
                if (front->right) {
                    _memo.insert({front->right, {p.first+1, p.second+1}});
                    que.push(front->right);
                }
            }

            auto it = cur.begin();
            while (it != cur.end()) {
                int col = it->first;
                auto& arr = it->second;
                sort(arr.begin(), arr.end());
                for (int i = 0; i < arr.size(); ++i) {
                    _relt[col].push_back(arr[i]);
                }
                ++it;
            }
        }

        vector<vector<int>> ans;
        auto it = _relt.begin();
        while (it != _relt.end()) {
            ans.push_back(it->second);
            ++it;
        }
        return ans;
    }
};

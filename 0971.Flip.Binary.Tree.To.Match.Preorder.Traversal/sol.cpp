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
    vector<int> _relt;
    bool _isValid;

    void dfs(TreeNode* root, vector<int>& voyage, int& k) {
        if (!root) return;

        if (!_isValid) {
            return ;
        }

        if (root->val != voyage[k]) {
            _isValid = false;
            return;
        } else {
            if (root->left) {
                if (voyage[k+1] == root->left->val) {
                    k++;
                    dfs(root->left, voyage, k);
                    if (root->right) {
                        k++;
                        dfs(root->right, voyage, k);
                    }
                } else {
                    _relt.push_back(root->val);
                    if (root->right) {
                        k++;
                        dfs(root->right, voyage, k);
                        k++;
                        dfs(root->left, voyage, k);
                    } else {
                        _isValid = false;
                        return ;
                    }

                }
            } else if (root->right) {
                if (voyage[k+1] == root->right->val) {
                    k++;
                    dfs(root->right, voyage, k);
                } else {
                    _isValid = false;
                    return ;
                }
            }
        }
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        _isValid = true;
        int k = 0;
        dfs(root, voyage, k);

        if (_isValid) return _relt;
        else            return {-1};
    }
};

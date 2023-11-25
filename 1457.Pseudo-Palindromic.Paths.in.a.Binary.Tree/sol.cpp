// 2023-11-25 15:13

class Solution {
private:
    int _relt;
    vector<int> _count;
    string _curPath;

    // bottle neck
    bool isPseudoPalindromic() {
        int oddTime = 0;
        int evenTime = 0;
        int length = 0;
        for (int i = 1; i < 10; ++i) {
            length += _count[i];
            if (_count[i]) {
                if (_count[i] % 2 == 0) ++evenTime;
                else ++oddTime;
            }
        }

        if (length % 2 == 0) {
            return oddTime == 0;
        } else {
            return oddTime == 1;
        }

        return false;
    }

    void dfs(TreeNode* node) {
        if (node) {
            _curPath += to_string(node->val);
            ++_count[node->val];

            if (node->left == nullptr && node->right == nullptr) {
                if (isPseudoPalindromic())
                    ++_relt;
            } else {
                if (node->left) {
                    dfs(node->left);
                    char lastElement = _curPath.back();
                    _curPath.pop_back();
                    --_count[lastElement - '0'];
                }
                if (node->right){
                    dfs(node->right);
                    char lastElement = _curPath.back();
                    _curPath.pop_back();
                    --_count[lastElement - '0'];
                }         
            }
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        _relt = 0;

        _count.resize(10, 0);
        dfs(root);

        return _relt;
    }
};

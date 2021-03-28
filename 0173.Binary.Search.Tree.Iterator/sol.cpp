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
class BSTIterator {
private:
    int _index;
    vector<int> _vals;
private:
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            dfs(node->left);
        }
        _vals.emplace_back(node->val);
        if (node->right != nullptr) {
            dfs(node->right);
        }
    }
public:
    BSTIterator(TreeNode* root) : _index(0) {
        dfs(root);
    }
    
    int next() {
        return _vals[_index++];
    }
    
    bool hasNext() {
        return (_index < _vals.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution() : m_maxLength(0) {

    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxLength(root);
        return m_maxLength;
    }
private:
    int maxLength(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            int left_max_len = maxLength(node->left);
            int right_max_len = maxLength(node->right);
            if (left_max_len + right_max_len > m_maxLength) {
                m_maxLength = left_max_len + right_max_len;
            }
            return 1 + (left_max_len > right_max_len ? left_max_len : right_max_len);
        }
    }
private:
    int m_maxLength;
};
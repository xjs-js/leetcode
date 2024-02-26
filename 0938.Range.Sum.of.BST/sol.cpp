// @date: 2024-02-26.周一.19:30
class Solution {
private:
    void InOrder(TreeNode* root, int low, int high, int& acc) {
        if (root == nullptr) return;
        int rootVal = root->val;

        // left child
        if (rootVal > low) {
            InOrder(root->left, low, high, acc);
        }

        // root
        if (low <= root->val && root->val <= high) {
            acc += root->val;
        }

        // right child
        if (rootVal < high) {
            InOrder(root->right, low, high, acc);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int acc = 0;
        InOrder(root, low, high, acc);
        return acc;
    }
};

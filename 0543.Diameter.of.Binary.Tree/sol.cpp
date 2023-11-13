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
    int _maxDiameter;
public:
    int maxHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;

        int curMaxDiameter = 0;
        int leftMaxHeight = 0;
        int rightMaxHeight = 0;
        if (root->left) {
            leftMaxHeight = maxHeight(root->left);
            curMaxDiameter += (1 + leftMaxHeight);
        }
        if (root->right) {
            rightMaxHeight = maxHeight(root->right);
            curMaxDiameter += (1 + rightMaxHeight);
        }
        int curMaxHeight = max(leftMaxHeight, rightMaxHeight) + 1;
        _maxDiameter = max(_maxDiameter, curMaxDiameter);
        return curMaxHeight;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        _maxDiameter = 0;
        maxHeight(root);
        return _maxDiameter;
    }
};

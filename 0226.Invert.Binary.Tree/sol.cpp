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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        
        if (root->left) {
            invertTree(root->left);
        }
        
        if (root->right) {
            invertTree(root->right);
        }
        
        swap(root->left, root->right);
        
        return root;
    }
};


// @date: 2024-02-22.周四.20:56
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* reversedLeft = invertTree(root->left);
            TreeNode* reversedRight = invertTree(root->right);

            root->left = reversedRight;
            root->right = reversedLeft;

            return root;
        }
        return nullptr;
    }
};
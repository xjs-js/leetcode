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
    TreeNode* buildTree(vector<int>& inorder, int inBeg, int inEnd, vector<int>& postorder, int postBeg, int postEnd) {
        TreeNode* root = nullptr;
        int rootVal = postorder[postEnd];
        root = new TreeNode(rootVal);
        int i = inBeg;
        while (i <= inEnd) {
            if (inorder[i] == rootVal) {
                break;
            }
            ++i;
        }
        int leftLen = i - inBeg;
        int rightLen = inEnd - i;
        if (leftLen > 0) {
            root->left = buildTree(inorder, inBeg, inBeg + leftLen - 1, postorder, postBeg, postBeg + leftLen - 1);
        }
        if (rightLen > 0) {
            root->right = buildTree(inorder, i+1, inEnd, postorder, postBeg + leftLen, postEnd-1);
        }
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
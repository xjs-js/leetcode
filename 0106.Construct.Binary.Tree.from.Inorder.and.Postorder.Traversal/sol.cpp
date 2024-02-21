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

// @date: 2024-02-21.Wed.21:55
class Solution {
public:
    int getIndex(vector<int>& arr, int val) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }

        int lastElement = postorder.back();
        int lastElementIndexInInorder = getIndex(inorder, lastElement);
        if (TreeNode* root = new TreeNode(lastElement)) {
            vector<int> leftInOrder(inorder.begin(), inorder.begin() + lastElementIndexInInorder);
            vector<int> rightInOrder(inorder.begin() + lastElementIndexInInorder + 1, inorder.end());

            int leftInOrderLen = leftInOrder.size();
            int rightInOrderLen = rightInOrder.size();

            vector<int> leftPostOrder(postorder.begin(), postorder.begin() + leftInOrderLen);
            vector<int> rightPostOrder(postorder.begin() + leftInOrderLen, postorder.begin() + leftInOrderLen + rightInOrderLen);

            root->left = buildTree(leftInOrder, leftPostOrder);
            root->right = buildTree(rightInOrder, rightPostOrder);

            return root;
        }
        
        return nullptr;
    }
};

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
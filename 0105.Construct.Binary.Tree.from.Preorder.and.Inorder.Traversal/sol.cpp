/**
 * @date: 2021-04-17 11:30 Sat.
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0]);
        }
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        
        auto rootPos = find(inorder.begin(), inorder.end(), rootVal);
        vector<int> leftInorder(inorder.begin(), rootPos);
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftInorder.size());
        
        vector<int> rightInorder(rootPos+1, inorder.end());
        vector<int> rightPreorder(preorder.begin()+1+leftInorder.size(), preorder.end());
        
        
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        
        return root;
    }
};
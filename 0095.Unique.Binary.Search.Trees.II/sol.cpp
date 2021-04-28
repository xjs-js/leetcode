
TreeNode* copy(TreeNode* root, int delta) {
    if (!root) return nullptr;
    
    TreeNode* newLeft = copy(root->left, delta);
    TreeNode* newRight = copy(root->right, delta);
    TreeNode* newRoot = new TreeNode(root->val  + delta, newLeft, newRight);
    return newRoot;
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(9);
        
        dp[0] = {nullptr};
        dp[1] = {new TreeNode(1)};
        dp[2] = {new TreeNode(1, nullptr, new TreeNode(2)),
                   new TreeNode(2, new TreeNode(1), nullptr)};
                
        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j <= i-1; ++j) {
                vector<TreeNode*> allLeft = dp[j];
                vector<TreeNode*> allRight = dp[i-1-j];
                
                int delta = j+1;
                vector<TreeNode*> newRight;
                for (TreeNode* rightNode: allRight) {
                    newRight.push_back(copy(rightNode, delta));
                }
                for (TreeNode* leftNode: allLeft) {
                    for (TreeNode* nr : newRight) {
                        TreeNode* root = new TreeNode(j+1, leftNode, nr);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};

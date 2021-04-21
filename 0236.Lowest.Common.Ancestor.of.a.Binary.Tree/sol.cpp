class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        unordered_map<TreeNode*, TreeNode*> dict;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* front = que.front();
            que.pop();
            if (front->left) {
                dict[front->left] = front;
                que.push(front->left);
            }
            if (front->right) {
                dict[front->right] = front;
                que.push(front->right);
            }
        }
        
        TreeNode* m = p, *n = q;
        while (m != n) {
            if (m == root) {
                m = q;
            } else {
                m = dict[m];
            }
            if (n == root) {
                n = p;
            } else {
                n = dict[n];
            }
        }
        return m;
    }
};
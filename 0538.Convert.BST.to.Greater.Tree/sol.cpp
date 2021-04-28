class Solution {
private:
    vector<TreeNode*> _nodes;
public:
    
    void preOrder(TreeNode* node) {
        if (!node) return;
        
        if (node->left) preOrder(node->left);
        _nodes.push_back(node);
        if (node->right) preOrder(node->right);
    }
    
    // 中序遍历，将所有节点保存到vector中，利用后缀和来计算出节点的值
    TreeNode* convertBST(TreeNode* root) {
        preOrder(root);
        
        int n = _nodes.size();
        int suffixSum = 0;
        for (int j = n-1; j >= 0; --j) {
            if (_nodes[j]) {
                suffixSum += _nodes[j]->val;
                _nodes[j]->val = suffixSum;
            }
        }
        
        return root;
    }
};
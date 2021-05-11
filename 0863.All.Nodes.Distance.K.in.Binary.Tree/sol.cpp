/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> _relt;
    
public:
    // 往下找距离node为k的子节点
    void dfs(TreeNode* node, int k) {
        if (!node) {
            return ;
        } else {
            if (k == 0) {
                _relt.push_back(node->val);
            }
            if (node->left) {
                dfs(node->left, k - 1);
            }
            
            if (node->right) {
                dfs(node->right, k - 1);
            }
        }
    }
    
    
    // 获取p的兄弟
    TreeNode* getSibling(map<TreeNode*, TreeNode*> parent, TreeNode* p) {
        if (TreeNode* par = parent[p]) {
            return par->left == p ? par->right : par->left;
        }
        return nullptr;
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // bfs 建立 parent和child的对应关系
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* p = que.front();
            que.pop();
            
            if (p->left) {
                parent[p->left] = p;
                que.push(p->left);
            }
            
            if (p->right) {
                parent[p->right] = p;
                que.push(p->right);
            }
        }
        
        TreeNode* p = target;
        if (k > 0) {
            dfs(target, k);
        }
        
        while (p && k >= 0) {
            if (k >= 2) {
                // 搜索兄弟节点的子树
                if (TreeNode* s = getSibling(parent, p)) {
                    dfs(s, k - 2);
                }
            } else if (k == 0) {
                _relt.push_back(p->val);
            }
            --k;
            // p往上迭代成父节点
            p = parent[p];
        }
        
        
        return _relt;
    }
};

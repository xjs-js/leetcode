/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    TreeNode* _root;
    vector<TreeNode*> _arr;
    int _level;
public: 
    // 先bfs将所有的节点放入到vector中
    // 之后利用下标关系来找父节点
    CBTInserter(TreeNode* root) : _root(root), _level(0) {
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                TreeNode* front = que.front();
                que.pop();
                if (front->left) que.push(front->left);
                if (front->right) que.push(front->right);

                _arr.push_back(front);
            }
            ++_level;
        }
    }
    
    int insert(int v) {
        // 满了
        if ((1 << _level) - 1 == _arr.size()) {
            ++_level;
        }

        int last = _arr.size() - 1;
        int idx = (last - 1) / 2;
        TreeNode* parent = _arr[idx];
        if (!parent->left) {
            parent->left = new TreeNode(v);
            _arr.push_back(parent->left);
            return parent->val;
        }
        else if (!parent->right) {
            parent->right = new TreeNode(v);
            _arr.push_back(parent->right);
            return parent->val;
        }
        else {
            parent = _arr[idx+1];
            parent->left = new TreeNode(v);
            _arr.push_back(parent->left);
            return parent->val;
        }
    }
    
    TreeNode* get_root() {
        return _root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

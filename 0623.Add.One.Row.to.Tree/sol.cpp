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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (1 == d) {
            TreeNode* newRoot = new TreeNode(v, root, nullptr);
            return newRoot;
        }

        std::queue<TreeNode*> que;
        que.push(root);

        while (true) {
            if (d == 2) {
                int size = que.size();

                /* each parent */
                for (int i = 0; i < size; ++i) {
                    if (TreeNode* parent = que.front()) {
                        que.pop();

                        // new node
                        TreeNode* newleftNode = new TreeNode(v, parent->left, nullptr);
                        TreeNode* newRightNode = new TreeNode(v, nullptr, parent->right);

                        // insert
                        parent->left = newleftNode;
                        parent->right = newRightNode;
                    }
                }

                break;
            }
            else {
                d--;
                int size = que.size();
                for (int i = 0; i < size; ++i) {
                    if (TreeNode* front = que.front()) {
                        que.pop();
                        if (TreeNode* leftChild = front->left) {
                            que.push(leftChild);
                        }
                        if (TreeNode* rightChild = front->right) {
                            que.push(rightChild);
                        }
                    }
                }
            }
        }

        return root;
    }
};
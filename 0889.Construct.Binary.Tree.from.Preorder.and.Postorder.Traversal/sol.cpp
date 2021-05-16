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
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        TreeNode* root = new TreeNode(pre[0]);
        
        if (n > 1) {
            int l = pre[1];
            int j = n - 2;
            for (; j >= 0; --j) {
                if (post[j] == l) {
                    break;
                }
            }
            
            vector<int> left_pre(j + 1);
            vector<int> left_post(j + 1);
            
            int beg = 1;
            for (int k = 0; k < j+1; ++k) {
                left_pre[k] = pre[beg++];
            }
            
            int end = j;
            for (int k = j; k >= 0; --k) {
                left_post[k] = post[end--];
            }
            
            root->left = constructFromPrePost(left_pre, left_post);
            
            if (j != n-2) {
                vector<int> right_pre(n-1-j-1);
                vector<int> right_post(n-1-j-1);
                
                for (int k = 0; k < n-1-j-1; ++k) {
                    right_pre[k] = pre[beg++];
                }
                
                end = n-2;
                for (int k = n-1-j-1-1; k >= 0; --k) {
                    right_post[k] = post[end--];
                }
                
                root->right = constructFromPrePost(right_pre, right_post);
            }
        }
        
        return root;
    }
};

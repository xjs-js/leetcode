/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// @date: 2024-02-22
class Solution {
public:
    int getIndex(vector<int>& arr, int val) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() || postorder.empty() || preorder.size() != postorder.size()) {
            return nullptr;
        }

        if (TreeNode* root = new TreeNode(preorder.front())) {
            if (preorder.size() > 1) {
                int leftRootInPre = 1;
                int leftRootInPost = getIndex(postorder, preorder[leftRootInPre]);

                int rightRootInPost = postorder.size() - 1 - 1;

                auto preorderLeftItbeg = preorder.begin() + leftRootInPre;
                auto preorderLeftItend = preorderLeftItbeg + leftRootInPost + 1;
                
                vector<int> preorderLeft(preorderLeftItbeg, preorderLeftItend);
                vector<int> preorderRight(preorderLeftItend, preorder.end());

                auto postorderLeftItbeg = postorder.begin();
                auto postorderLeftItend = postorder.begin() + leftRootInPost + 1;
                
                vector<int> postorderLeft(postorderLeftItbeg, postorderLeftItend);
                vector<int> postorderRight(postorderLeftItend, postorder.end() - 1);
                
                root->left = constructFromPrePost(preorderLeft, postorderLeft);
                root->right = constructFromPrePost(preorderRight, postorderRight);
            }
            return root;
        } else {
            return nullptr;
        }
    }
};


// @date: 2021年5月17日
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

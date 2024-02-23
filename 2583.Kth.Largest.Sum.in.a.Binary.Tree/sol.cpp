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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int qSize = que.size();
            long long curLevelSum = 0;
            while (qSize--) {
                if (TreeNode* top = que.front()) {
                    curLevelSum += (long long)top->val;
                    if (top->left) que.push(top->left);
                    if (top->right) que.push(top->right);
                }
                que.pop();
            }
            if (minHeap.size() < k) {
                minHeap.push(curLevelSum);
            } else {
                long long minHeapTop = minHeap.top();
                if (curLevelSum >= minHeapTop) {
                    minHeap.pop();
                    minHeap.push(curLevelSum);
                }
            }
        }


        int minHeapSize = minHeap.size();
        if (minHeapSize < k) {
            return -1;
        } else {
            return minHeap.top();
        }

        return -1;
    }
};

/**
 * @date: 2021-04-16 16:25 Fri.
 * @cat: 二叉树
 */


class Solution {
public:
    TreeNode* makeBST(vector<int>& nums, int beg, int end) {
        int N = end - beg + 1;
        
        if (N == 1) {
            TreeNode* newNode = new TreeNode(nums[beg]);
            return newNode;
        }
        
        if (N == 2) {
            TreeNode* newNode = new TreeNode(nums[beg]);
            TreeNode* newNode_2 = new TreeNode(nums[end]);
            newNode->right = newNode_2;
            return newNode;
        }
        
        if (N == 3) {
            TreeNode* leftNode = new TreeNode(nums[beg]);
            TreeNode* rightNode = new TreeNode(nums[end]);
            TreeNode* middleNode = new TreeNode(nums[beg+1], leftNode, rightNode);
            
            return middleNode;
        }
        
        int mid = beg + N / 2;
        
        TreeNode* leftNode = makeBST(nums, beg, mid-1);
        TreeNode* rightNode = makeBST(nums, mid+1, end);
        TreeNode* middleNode = new TreeNode(nums[mid], leftNode, rightNode);
        return middleNode;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size() - 1);
    }
};
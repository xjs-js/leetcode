class Solution {
public:
    TreeNode* buildBST(vector<int>& vals, int beg, int end) {
        if (beg > end) return nullptr;
        
        int nums = end - beg + 1;
        
        if (nums == 1) {
            return new TreeNode(vals[beg]);
        }
        
        if (nums == 2) {
            return new TreeNode(vals[beg], nullptr, new TreeNode(vals[end]));
        }
        
        if (nums == 3) {
            return new TreeNode(vals[beg+1], new TreeNode(vals[beg]), new TreeNode(vals[end]));
        }
        
        
        int mid = (beg + end) / 2;
        TreeNode* root = new TreeNode(vals[mid]);
        TreeNode* left = buildBST(vals, beg, mid-1);
        TreeNode* right = buildBST(vals, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
        
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        vector<int> vals;
        while (p) {
            vals.push_back(p->val);
            p = p->next;
        }
        
        return buildBST(vals, 0, vals.size()-1);
    }
};

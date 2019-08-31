class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 && t2 )
        {
            TreeNode* t = new TreeNode(t1->val + t2->val);
            t->val   = t1->val + t2->val;
            t->left  = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
            return t;
        }
        else if ( t1 && !t2 )
        {
            return t1;
        }
        else if ( !t1 && t2 )
        {
            return t2;
        }
        else if ( !t1 && !t2 )
        {
            return nullptr;
        }
        return nullptr;
    }
};

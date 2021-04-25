class Solution {
public:
    unordered_map<int, vector<TreeNode*>> _memo;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        cout << n << endl;
        // n 为偶数是不可能建立出满二叉树的
        if (n % 2 == 0) {
            return {};
        }
        
        if (n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        
        if (n == 3) {
            TreeNode* childL = new TreeNode(0);
            TreeNode* childR = new TreeNode(0);
            TreeNode* root = new TreeNode(0, childL, childR);
            return {root};
        }
        
        if (_memo.find(n) != _memo.end()) {
            return _memo[n];
        }
        
        vector<TreeNode*> relt;
        TreeNode* root = nullptr;
        for (int i = 1; i <= (n-1)/2; i += 2) {
            int leftNum = i;
            int rightNum = (n-1) - i;
            
            vector<TreeNode*> allLeft = allPossibleFBT(leftNum);
            vector<TreeNode*> allRight = allPossibleFBT(rightNum);


            for (int l = 0; l < allLeft.size(); ++l) {
                for (int r = 0; r < allRight.size(); ++r) {
                    root = new TreeNode(0, allLeft[l], allRight[r]);
                    relt.emplace_back(root);
                    
                    if (leftNum != rightNum) {
                        root = new TreeNode(0, allRight[r], allLeft[l]);
                        relt.emplace_back(root);
                    }
                }
            }
        }
        
        _memo[n] = relt;
        return relt;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] 表示 第i个格子能否跳到最后
        vector<bool> dp(n, false);
        
        // 最后一个格子
        dp[n-1] = true;
        
        for (int i = n-2; i >= 0; --i) {
            int curStep = nums[i];
            
            for (int j = 1; j <= curStep && i+j <= n - 1; ++j) {
                if (dp[i+j]) {
                    dp[i] = true;
                    break;
                }
            }
            // cout << "i" << i <<  dp[i] << endl;
        }
        
        return dp[0];
    }
};

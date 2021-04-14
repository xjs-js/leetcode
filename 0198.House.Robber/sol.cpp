/**
 * @date: 2021-04-16 00:32 Thur.
 * @cat: 动态规划
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int N = nums.size();
        int** dp = new int*[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = new int[2];
        }
        
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];
        int slowMax = nums[0];
        for (int i = 2; i < N; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = slowMax + nums[i];
            slowMax = max(slowMax, dp[i-1][1]);
        }
        
        return max(dp[N-1][0], dp[N-1][1]);
    }
};
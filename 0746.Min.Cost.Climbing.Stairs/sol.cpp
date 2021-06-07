class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 简单dp
        int n = cost.size();
        int dp[n+1];
        memset(dp, -1, sizeof dp);
        
        dp[0] = 0; dp[1] = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 <= n) dp[i+1] = dp[i+1] == -1 ? cost[i] + dp[i] : min(dp[i+1], dp[i] + cost[i]);
            if (i + 2 <= n) dp[i+2] = dp[i+2] == -1 ? cost[i] + dp[i] : min(dp[i+2], dp[i] + cost[i]);
        }
        
        return dp[n];
    }
};

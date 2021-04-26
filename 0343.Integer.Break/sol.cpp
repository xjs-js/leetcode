class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            int curRelt = 0;
            for (int j = i-1; j >= 1; --j) {
                curRelt = max(curRelt, max(dp[j],j) * (i-j));
            }
            
            dp[i] = curRelt;
            // cout << i << "dp[i] " << dp[i] << endl;
        }
        
        return dp[n];
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        set<int> onlyNum;
        unordered_map<int, int> count;
        
        for (int n : nums) {
            onlyNum.insert(n);
            ++count[n];
        }
        
        vector<int> newNums(onlyNum.begin(), onlyNum.end());
        int n = newNums.size();
        
        vector<vector<int>> dp(n, vector<int>(2));
        
        dp[0][0] = 0;
        dp[0][1] = newNums[0] * count[newNums[0]];
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            if (newNums[i] != newNums[i-1] + 1) {
                dp[i][1] = newNums[i] * count[newNums[i]] + max(dp[i-1][0], dp[i-1][1]);
            } else {
                dp[i][1] = newNums[i] * count[newNums[i]] + dp[i-1][0];
            }
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

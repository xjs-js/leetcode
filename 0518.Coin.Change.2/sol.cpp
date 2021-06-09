class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        /* init */
        int** dp = new int*[n+1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new int[amount+1];
            for (int j = 0; j <= amount; ++j) {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }


        for (int i = 1; i <= n; ++i) {
            int cur = coins[i-1];
            for (int j = 0; j <= amount; ++j) {
                if (j >= cur) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-cur];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return dp[n][amount];
    }
};

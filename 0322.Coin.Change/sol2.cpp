/* 完全背包问题 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int** dp = new int*[n+1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = new int[amount+1];

            for (int j = 0; j <= amount; ++j) {
                if (j == 0) dp[i][j] = 0;
                else        dp[i][j] = -1;
            }
        }


        for (int i = 1; i <= n; ++i) {
            int cur = coins[i-1];
            for (int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i-1][j];

                if (j >= cur && dp[i][j-cur] >= 0) {
                    dp[i][j] = dp[i][j] == -1 ? dp[i][j-cur] + 1 : min(dp[i][j], dp[i][j-cur]+1);
                }
            }
        }

        return dp[n][amount];
    }
};

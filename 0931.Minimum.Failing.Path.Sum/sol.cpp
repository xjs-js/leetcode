class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        /* 第一行相等 */
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }

        /* 其余行用递推关系式  dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);  */
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] + dp[i-1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j-1]);
                }
                if (j + 1 < n) {
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i-1][j+1]);
                }
            }
        }

        /* 最后一行找出最小的值 */
        int relt = dp[n-1][0];
        for (int i = 1 ; i < n; ++i) {
            relt = min(relt, dp[n-1][i]);
        }
        return relt;
    }
};

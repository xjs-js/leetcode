class Solution {
public:
    /* 完全背包问题 */
    int package(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target+1, -1));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            int cur = arr[i-1];
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];

                if (j >= cur) {
                    if (dp[i][j - cur] >= 0) {
                        dp[i][j] = dp[i][j] == -1 ? dp[i][j-cur] + 1 : min(dp[i][j], dp[i][j-cur] + 1);
                    }
                }
            }
        }

        return dp[n][target];
    }

    int numSquares(int n) {
        int i = 1;
        vector<int> arr;
        while (i*i <= n) {
            arr.push_back(i*i);
            ++i;
        }

        return package(arr, n);
    }
};

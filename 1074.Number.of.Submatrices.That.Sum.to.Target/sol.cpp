class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        int relt = 0;
        
        for (int r1 = 1; r1 <= m; ++r1) {
            for (int r2 = r1; r2 <= m; ++r2) {
                unordered_map<int, int > count;
                for (int col = 1; col <= n; ++col) {
                    int sum = dp[r2][col] + dp[r1-1][0] - dp[r2][0] - dp[r1-1][col];
                    if (sum == target) {
                        ++relt;
                    }
                    relt += count[sum - target];
                    // printf("(%d, %d, %d) = %d\t", r1, r2, col, sum);
                    // cout << count[sum-target] << endl;
                    ++count[sum];
                }
            }
        }

        return relt;
    }
};

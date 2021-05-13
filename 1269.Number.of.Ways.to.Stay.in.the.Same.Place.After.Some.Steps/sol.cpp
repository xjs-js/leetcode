

class Solution {
public:
    // dp[i][j] 表示传了i次，最后停到j的次数
    // 返回dp[steps][0]
    // dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
    // 滚动数组
    int numWays(int steps, int arrLen) {
        arrLen = min(steps, arrLen);
        
        int* prev = new int[arrLen];
        int* cur = new int[arrLen];
        for (int i = 0; i < arrLen; ++i) {
            prev[i] = 0;
            cur[i] = 0;
        }
        int MOD = 1e9 + 7;
        prev[0] = 1;
        
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j < arrLen; ++j) {
                cur[j] = prev[j] % MOD;
                if (j - 1 >= 0) {
                    cur[j] = (cur[j] % MOD + prev[j-1] % MOD) % MOD;
                }
                if (j + 1 < arrLen) {
                    cur[j] = (cur[j] % MOD + prev[j+1] % MOD) % MOD;
                }
            }
          
            for (int j = 0; j < arrLen; ++j) {
                prev[j] = cur[j];
            }

        }
        
        return cur[0] % MOD;
    }
};

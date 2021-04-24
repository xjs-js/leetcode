int MOD = 1e9+7;
class Solution {
public:

    int numTilings(int N) {

        vector<int> dp(1001);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        dp[4] = 11;

        for (int i = 5; i <= N; ++i) {
            dp[i] += dp[i-1] % MOD;
            dp[i] += dp[i-2] % MOD;
            for (int j = 3; j <= i; ++j) {
                dp[i] = (dp[i] % MOD + (2 * dp[i-j]) % MOD) % MOD;
            }
        }
        return dp[N];
    }
};
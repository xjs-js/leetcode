/**
 * @date: 2021-03-30 22:10
 * @follow-up: 刚刚看完小米的发布会，雷总要开始造车了，祝好
 */


class Solution {
public:
    /**
     * 看上去像是简单的贪心算法
     * dp[i][0] 表示第i个不拿，所能达到的最大数量
     * dp[i][1] 表示第i个一定拿，所能达到的最大数量
     *
     * 状态转移方程
     * dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
     * dp[i][1] = max{dp[j][1] + 1}, where envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]
     *
     * 最后返回 max(dp[i][0], dp[i][1]);
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 什么都不管，上来先排序
        sort(envelopes.begin(), envelopes.end());

        int N = envelopes.size();

        // new space
        int** dp = new int*[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = new int[2];
        }

        // 初始状态
        dp[0][0] = 0;
        dp[0][1] = 1;

        for (int i = 1; i < envelopes.size(); ++i) {
            const vector<int>& cur = envelopes[i];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            int curMax = 1;
            for (int j = i-1; j >= 0; --j) {
                const vector<int>& prev = envelopes[j];
                if (cur[0] > prev[0] && cur[1] > prev[1]) {
                    curMax = max(curMax, dp[j][1] + 1);
                }
            }
            dp[i][1] = curMax;
        }

        int result = max(dp[N-1][0], dp[N-1][1]);

        // delete space
        for (int i = 0; i < N; ++i) {
            delete[] dp[i];
        }
        delete[] dp;

        return result;
    }
};
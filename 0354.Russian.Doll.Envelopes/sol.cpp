/**
 * @date: 2021-03-30 22:10
 * @follow-up: 刚刚看完小米的发布会，雷总要开始造车了，祝好
 */

#include "../headers.h"

class Solution {
public:
    /**
     * 看上去像是简单的贪心算法
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 什么都不管，上来先排序
        sort(envelopes.begin(), envelopes.end());

        // for (size_t i = 0; i < envelopes.size(); ++i) {
        //     cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
        // }

        int N = envelopes.size();
        int** dp = new int*[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = new int[2];
        }

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
        for (int i = 0; i < N; ++i) {
            delete[] dp[i];
        }

        delete[] dp;

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    //vector<vector<int> > vec{{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    // vector<vector<int> > vec{{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    vector<vector<int> > vec{{46,89}, {50,53}, {52,68}, {72,45}, {77,81}};
    cout << sol.maxEnvelopes(vec) << endl;

    return 0;
}
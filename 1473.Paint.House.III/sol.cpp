class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int*** dp = new int**[m];
        for (int i = 0; i < m; ++i) {
            dp[i] = new int*[n+1];
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = new int[target+1];
                for (int l = 0; l <= target; ++l) {
                    dp[i][j][l] = -1;
                }
            }
        }
        
        if (houses[0] == 0) {
            for (int c = 1; c <= n; ++c) {
                dp[0][c][1] = cost[0][c-1];
            }
        } else {
            int c = houses[0];
            dp[0][c][1] = 0;
        }
        
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int k = 1; k <= i+1 && k <= target; ++k) {
                    for (int c = 1; c <= n; ++c) {
                        for (int prevC = 1; prevC <= n; ++prevC) {
                            if (prevC != c && dp[i-1][prevC][k-1] != -1) {
                                dp[i][c][k] = dp[i][c][k] == -1 ? dp[i-1][prevC][k-1] : min(dp[i][c][k], dp[i-1][prevC][k-1]);
                            } else if (prevC == c && dp[i-1][prevC][k] != -1) {
                                dp[i][c][k] = dp[i][c][k] == -1 ? dp[i-1][prevC][k] : min(dp[i][c][k], dp[i-1][prevC][k]);
                            }
                        }
                        if (dp[i][c][k] != -1) {
                            dp[i][c][k] += cost[i][c-1];
                        }
                    }
                }
            } else {
                int c = houses[i];
                
                for (int k = 1; k <= i+1 && k <= target; ++k) {
                    for (int prevC = 1; prevC <= n; ++prevC) {
                        if (prevC != c && dp[i-1][prevC][k-1] != -1) {
                            dp[i][c][k] = dp[i][c][k] == -1 ? dp[i-1][prevC][k-1] : min(dp[i][c][k], dp[i-1][prevC][k-1]);
                        } else if (prevC == c && dp[i-1][prevC][k] != -1) {
                            dp[i][c][k] = dp[i][c][k] == -1 ? dp[i-1][prevC][k] : min(dp[i][c][k], dp[i-1][prevC][k]);
                        }
                    }
                }
            }
        }
        
        // dp[m-1][c][target];
        
        int relt = -1;
        for (int c = 1; c <= n; ++c) {
            if (dp[m-1][c][target] != -1) {
                relt = relt == -1 ? dp[m-1][c][target] : min (relt, dp[m-1][c][target]);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                delete[] dp[i][j];
            }
            delete[] dp[i];
        }
        delete[] dp;
        
        return relt;
    }
};

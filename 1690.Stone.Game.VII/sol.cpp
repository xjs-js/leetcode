
class Solution {
private:
    int _relt;
    vector<vector<int>> _dp;

public:
    void calc(vector<int>& stones, int i , int j) {
        if (i == j) {
            _dp[i][j] = 0;
        } else if (i + 1 == j) {
            _dp[i][j] = max(stones[i], stones[j]);
        } else {
            
            int relt_1 = stones[i+1] + _dp[i+2][j];
            int relt_2 = stones[j] + _dp[i+1][j-1];
            int relt_3 = stones[i] + _dp[i+1][j-1];
            int relt_4 = stones[j-1] + _dp[i][j-2];
            
            
            _dp[i][j] = max(min(relt_1, relt_2), min(relt_3, relt_4));
        }
    }


    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        _dp.resize(n, vector<int>(n, 0));
        
        for (int k = 0; k <= n-1; ++k) {
            for (int i = 0; i <= n-1; ++i) {
                int j = i + k;
                if (j < n) {
                    calc(stones, i, j);
                }
            }
        }
    
        
        return _dp[0][n-1];
    }
};

class Solution {
public:
    unordered_map<int,int> _isExist;
    int _maxNum;

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            int curNum = arr[i];
            _isExist[curNum] = i;
        }

        int maxLen = 0;
        for (int j = n-1; j >= 0; --j) {
            for (int i = j-1; i >= 0; --i) {
                int first = arr[i];
                int second = arr[j];
                int third = first + second;
                if (_isExist.find(third) != _isExist.end()) {
                    dp[i][j] = 1 + dp[j][_isExist[third]];
                } else {
                    dp[i][j] = 2;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        
        
        return (maxLen >= 3) ? maxLen : 0;
    }
};

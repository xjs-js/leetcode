class Solution {
public:
    int minDistance(string word1, string word2) {
        // 最长公共子序列
        
        int m = word1.size(), n = word2.size();
        int** lcs = new int*[m+1];
        for (int i = 0; i <= m; ++i) {
            lcs[i] = new int[n+1];
            for (int j = 0; j <= n; ++j) {
                lcs[i][j] = 0;
            }
        }
        
        word1 = " " + word1;
        word2 = " " + word2;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i] == word2[j]) {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        
        return m + n - 2 * lcs[m][n];
    }
};

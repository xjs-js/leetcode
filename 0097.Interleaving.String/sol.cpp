class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0) {
            return s3 == s2;
        } else if (s2.size() == 0) {
            return s1 == s3;
        }
        
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;

        int m = s1.size(), n = s2.size();
        bool dp[m][n];
        memset(dp, 0, sizeof dp);


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                    continue;
                }

                if (s3[i+j] == s1[i]) {
                    dp[i][j] |= dp[i-1][j];      
                }
                
                if (s3[i+j] == s2[j]) {
                    dp[i][j] |= dp[i][j-1];     
                }
            }
        }

        return dp[m-1][n-1];
    }
};

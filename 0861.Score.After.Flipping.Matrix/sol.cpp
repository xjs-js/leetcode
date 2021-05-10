class Solution {
public:
    // 翻转一行
    void flipRow(vector<vector<int>>& A, int row) {
        int n = A[0].size();
        
        for (int i = 0; i < n; ++i) {
            A[row][i] = !A[row][i];
        }
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        
        // 每行第一个不为1，就翻转
        for (int i = 0; i < m; ++i) {
            if (!A[i][0]) {
                flipRow(A, i);
            }
        }
        
        int relt = 0;
        // 每一列，0的个数大于1的个数就翻转
        for (int j = 0; j < n; ++j) {
            int numOf0 = 0;
            for (int i = 0; i < m; ++i) {
                if (A[i][j] == 0) {
                    ++numOf0;
                }
            }
            int numOf1 = m - numOf0;
            relt += max(numOf0, numOf1) * pow(2, n-1-j);
        }
        
        return relt;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
 
        // 对角线的数量
        int numOfDia = m + n - 1;
        
        vector<int> relt;
        for (int i = 1; i <= numOfDia; ++i) {
            if (i % 2 == 1) { // 从下到上
                int row = i - 1, col = 0;   // 起点
                while (row >= m) {          // 修正起点
                    --row;
                    ++col;
                }
                
                while (0 <= row && col < n) {       // 往上迭代
                    relt.push_back(mat[row][col]);
                    --row;
                    ++col;
                }
            } else {    // 从上到下
                int row = 0, col = i - 1;       // 起点
                while (col >= n) {              // 修正起点
                    --col;
                    ++row;
                }
                
                while (col >= 0 && row < m) {       // 往下迭代
                    relt.push_back(mat[row][col]);
                    ++row;
                    --col;
                }
            }
        }
        
        return relt;
    }
};

/**
 * @date: 2021-04-15 20:49 Thur.
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int beg, int end) {
        int N = end - beg + 1;
        
        vector<int> row_0(N);
        vector<int> col_1(N);
        vector<int> row_2(N);
        vector<int> col_3(N);
        
        int j = 0;
        for (int i = beg; i <= end; ++i,++j) {
            row_0[j] = matrix[beg][i];
            col_1[j] = matrix[i][end];
            row_2[j] = matrix[end][i];
            col_3[j] = matrix[i][beg];
        }
        
        j = 0;
        for (int i = beg; i <= end; ++i, ++j) {
            matrix[beg][i] = col_3[N-1-j];
            matrix[i][end] = row_0[j];
            matrix[end][i] = col_1[N-1-j];
            matrix[i][beg] = row_2[j];
        }
        
    
        if (N-2 >= 2) {
            rotate(matrix, beg+1, end-1);
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        if (N == 0 || N == 1) {
            return ;
        }
        
        rotate(matrix, 0, N-1);
    }
};
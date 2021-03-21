class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t row = matrix.size();
        size_t col = matrix[0].size();

        std::bitset<200> rowMemo;
        std::bitset<200> colMemo;

        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                if (0 == matrix[i][j]) {
                    rowMemo.set(i, true);
                    colMemo.set(j, true);
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            if (rowMemo[i] == true) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < col; ++j) {
            if (colMemo[j] == true) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
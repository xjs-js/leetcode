/**
 * @date: 2021-04-01 20:29
 * @note: 第303题目偷鸡取巧了，这题要认真
 * @update: 2021-04-20 这题目做的不对，应该用前缀和的
 */


class NumMatrix {
private:
    int** _sum;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        _sum = new int*[row];
        for (size_t i = 0; i < row; ++i) {
            _sum[i] = new int[col];
            for (int j = 0; j < col; ++j) {
                _sum[i][j] = 0;
            }
        }

        _sum[0][0] = matrix[0][0];
        for (size_t j = 1; j < col; ++j) {
            _sum[0][j] = _sum[0][j-1] + matrix[0][j];
        }

        for (size_t i = 1; i < row; ++i) {
            _sum[i][0] = _sum[i-1][0] + matrix[i][0];
        }

        for (size_t i = 1; i < row; ++i) {
            for (size_t j = 1; j < col; ++j) {
                _sum[i][j] = _sum[i][j-1] + _sum[i-1][j] - _sum[i-1][j-1] + matrix[i][j];
            }
        }
        
        
    }
    
    int pre_sum(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        return _sum[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum(row2, col2) - pre_sum(row2, col1-1) - pre_sum(row1-1, col2) + pre_sum(row1-1, col1-1);
    }
};
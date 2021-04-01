/**
 * @date: 2021-04-01 20:29
 * @note: 第303题目偷鸡取巧了，这题要认真
 */


class NumMatrix {
private:
    int** sum;
    vector<vector<int>> _matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) 
        : _matrix(matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        sum = new int*[row];
        for (size_t i = 0; i < row; ++i) {
            sum[i] = new int[col];
        }


        for (size_t i = 0; i < row; ++i) {
            int acc = 0;
            for (size_t j = 0; j < col; ++j) {
                acc += matrix[i][j];
                sum[i][j] = acc;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (size_t i = row1; i <= row2; ++i) {
            result += sum[i][col2] - sum[i][col1] + _matrix[i][col1];
        }

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */


int main(int argc, char* argv[])
{

}

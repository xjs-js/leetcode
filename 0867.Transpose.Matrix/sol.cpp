class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();

        vector<vector<int>> result;
        result.resize(column);
        for (int i = 0; i < column; ++i) {
            result[i].resize(row);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};
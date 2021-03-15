class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // first find row and column
        int row = matrix.size();
        int column = matrix[0].size();

        int j_min = 0;
        int j_max = column - 1;
        
        int i_min = 0;
        int i_max = row - 1;

        // increase i and j to from min to max
        vector<int> result;
        while (j_min <= j_max || i_min <= i_max) {
            int curRow = i_min;
            int curCol = j_min;
            while (curCol <= j_max) {
                result.push_back(matrix[curRow][curCol]);
                ++curCol;
            }
            curCol = j_max;

            if (result.size() == column * row)
                return result;

            curRow = i_min + 1;
            while (curRow <= i_max) {
                result.push_back(matrix[curRow][curCol]);
                ++curRow;
            }
            curRow = i_max;

            if (result.size() == column * row)
                return result;

            curCol = j_max - 1;
            while (curCol >= j_min) {
                result.push_back(matrix[curRow][curCol]);
                --curCol;
            }
            curCol = j_min;

            if (result.size() == column * row)
                return result;

            curRow = i_max - 1;
            while (curRow > i_min) {
                result.push_back(matrix[curRow][curCol]);
                --curRow;
            }

            if (result.size() == column * row)
                return result;

            ++i_min;
            ++j_min;
            --j_max;
            --i_max;
        }

        return result;
    }
};
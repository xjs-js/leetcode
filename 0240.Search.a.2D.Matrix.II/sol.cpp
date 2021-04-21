class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, int rowBeg, int rowEnd, int colBeg, int colEnd) {
        if (rowBeg > rowEnd || colBeg > colEnd) {
            return false;
        }

        int m = rowEnd - rowBeg + 1;
        int n = colEnd - colBeg + 1;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (matrix[rowBeg + i][colBeg + j] < target) {
                i = i + 1;
                j = j + 1;
            } else if (matrix[rowBeg + i][colBeg + j] == target) {
                return true;
            } else {
                break;
            }
        }

        return searchMatrix(matrix, target, rowBeg + i, rowEnd, colBeg, colBeg + j - 1)
            || searchMatrix(matrix, target, rowBeg, rowBeg + i - 1, colBeg + j, colEnd);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        return searchMatrix(matrix, target, 0, m-1, 0, n-1);
    }
};
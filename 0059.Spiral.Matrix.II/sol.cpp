class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        // malloc some space
        result.resize(n);
        for (int i = 0; i < n; ++i) {
            result[i].resize(n);
        }

        // first find row and column
        int row = n;
        int column = n;

        int j_min = 0;
        int j_max = column - 1;
        
        int i_min = 0;
        int i_max = row - 1;

        // increase i and j to from min to max
        int curNum = 0;
        while (j_min <= j_max || i_min <= i_max) {
            int curRow = i_min;
            int curCol = j_min;
            while (curCol <= j_max) {
                result[curRow][curCol] = ++curNum;
                ++curCol;
            }
            curCol = j_max;

            if (curNum > n * n)
                return result;

            curRow = i_min + 1;
            while (curRow <= i_max) {
                result[curRow][curCol] = ++curNum;
                ++curRow;
            }
            curRow = i_max;

            if (curNum > n * n)
                return result;

            curCol = j_max - 1;
            while (curCol >= j_min) {
                result[curRow][curCol] = ++curNum;
                --curCol;
            }
            curCol = j_min;

            if (curNum > n * n)
                return result;

            curRow = i_max - 1;
            while (curRow > i_min) {
                result[curRow][curCol] = ++curNum;
                --curRow;
            }

            if (curNum > n * n)
                return result;

            ++i_min;
            ++j_min;
            --j_max;
            --i_max;
        }

        return result;
    }
};
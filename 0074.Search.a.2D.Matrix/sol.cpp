class Solution {
private:
    bool binarySearch(const vector<int>& curRow, int target) {
        int N = curRow.size();

        int start = 0;
        int end = N;

        while (start < end) {
            int mid = ( start + end ) / 2;
            int cur = curRow[mid];
            if (cur == target) {
                return true;
            } else if (cur < target) {
                start = mid + 1;
            } else if (cur > target) {
                end = end - 1;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        for (size_t i = 0; i < row; ++i) {
            vector<int>& curRow = matrix[i];

            int start = curRow[0];
            int end = curRow[col-1];

            if (start > target) {
                return false;
            } else if (end < target) {
                continue;
            } else {
                return binarySearch(curRow, target);
            }
        }

        return false;
    }
};
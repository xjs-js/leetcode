class Solution {
public:
    // 遍历三遍
    int projectionArea(vector<vector<int>>& grid) {
        int relt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            int curRow = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                    ++relt;
                curRow = max(curRow, grid[i][j]);
            }
            relt += curRow;
        }
        
        for (int j = 0; j < n; ++j) {
            int curCol = 0;
            for (int i = 0; i < m; ++i) {
                curCol = max(curCol, grid[i][j]);
            }
            relt += curCol;
        }
        
        return relt;
    }
};

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int relt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // bottom and up
                if (grid[i][j]) {
                    relt += 2;
                    
                    // around
                    // left
                    if (j == 0) {
                        relt += grid[i][j];
                    } else {
                        relt += (grid[i][j-1] >= grid[i][j]) ? 0 : grid[i][j] - grid[i][j-1];
                    }
                    
                    // front
                    if (i == 0) {
                        relt += grid[i][j];
                    } else {
                        relt += (grid[i-1][j] >= grid[i][j]) ? 0 : grid[i][j] - grid[i-1][j];
                    }
                    
                    // back
                    if (i == m-1) {
                        relt += grid[i][j];
                    } else {
                        relt += (grid[i+1][j] >= grid[i][j]) ? 0 : grid[i][j] - grid[i+1][j];
                    }
                    
                    // right
                    if (j == n-1) {
                        relt += grid[i][j];
                    } else {
                        relt += (grid[i][j+1] >= grid[i][j]) ? 0 : grid[i][j] - grid[i][j+1];
                    }
                    
                }
            }
        }
        
        return relt;
    }
};

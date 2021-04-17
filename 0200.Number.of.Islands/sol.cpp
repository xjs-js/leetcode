/**
 * @date: 2021-04-17 15:32 Sat.
 */
class Solution {
public:
    bool** _visit;
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        _visit[i][j] = true;
        
        // up
        if (i-1 >= 0 && _visit[i-1][j] == false && grid[i-1][j] == '1') {
            dfs(grid, i-1, j);
        }
        
        // down
        if (i + 1 < grid.size() && _visit[i+1][j] == false && grid[i+1][j] == '1') {
            dfs(grid, i+1, j);
        }
        
        // left
        if (j - 1 >= 0 && _visit[i][j-1] == false && grid[i][j-1] == '1') {
            dfs(grid, i, j-1);
        }
        
        // right
        if (j + 1 < grid[0].size() && _visit[i][j+1] == false && grid[i][j+1] == '1') {
            dfs(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        _visit = new bool*[row];
        for (int i = 0; i < row; ++i)  {
            _visit[i] = new bool[col];
            for (int j = 0; j < col; ++j) {
                _visit[i][j] = false;
            }
        }
    
        int count = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (_visit[i][j] == false && grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
    
        return count;
    }
};
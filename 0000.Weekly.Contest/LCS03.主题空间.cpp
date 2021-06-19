class Solution {
private:
    vector<vector<bool>> _isVisited;
    vector<string> _grid;
    int m;
    int n;
    unordered_map<int, int> _count;
    unordered_map<int, bool> _isSide;
    unordered_map<int, char> _num;
public:
    void dfs(int i, int j, int color) {
        _isVisited[i][j] = true;
        ++_count[color];
        if (i == 0 || i == m - 1 || j == 0 || j == n-1) {
            _isSide[color] = true;
        }
        
        char curTheme = _grid[i][j];
        _num[color] = curTheme;
        int x[4] = {-1, 0, +1, 0};
        int y[4] = {0, +1, 0, -1};
        
        for (int k = 0; k < 4; ++k) {
            int n_x = i + x[k];
            int n_y = j + y[k];
            if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n) {
                if (_grid[n_x][n_y] == '0') {
                    _isSide[color] = true;
                }
                if (curTheme == _grid[n_x][n_y]) {
                    if (!_isVisited[n_x][n_y]) {
                        dfs(n_x, n_y, color);
                    }
                }
            }
        }
    }
    
    int largestArea(vector<string>& grid) {
        m = grid.size();
        n = grid[0].size();
        _grid = grid;
        
        _isVisited.resize(m, vector<bool>(n, false));
        
        int color = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!_isVisited[i][j]) {
                    dfs(i, j, color);
                    ++color;
                }
            }
        }
        
        int relt = 0;
        auto it = _count.begin();
        while (it != _count.end()) {
            if (!_isSide[it->first] && _num[it->first] != '0') {
                relt = max(relt, it->second);
            }
            
            ++it;
        }
        return relt;
    }
};


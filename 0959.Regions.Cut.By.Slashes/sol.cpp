class Solution {
private:
    vector<string> _grid;
    vector<vector<vector<bool>>> _isVisited;
    int _n;

    void dfs(int i, int j, int k) {
        _isVisited[i][j][k] = true;

        if (_grid[i][j] == ' ') {
            for (int m = 0; m < 4; ++m) {
                if (!_isVisited[i][j][m]) {
                    dfs(i, j, m);
                }
            }
        } else if (_grid[i][j] == '/') {
            if (k == 0 && !_isVisited[i][j][3]) dfs(i, j, 3);
            if (k == 1 && !_isVisited[i][j][2]) dfs(i, j, 2);
            if (k == 2 && !_isVisited[i][j][1]) dfs(i, j, 1);
            if (k == 3 && !_isVisited[i][j][0]) dfs(i, j, 0);
        } else if (_grid[i][j] == '\\') {
            if (k == 0 && !_isVisited[i][j][1]) dfs(i, j, 1);
            if (k == 1 && !_isVisited[i][j][0]) dfs(i, j, 0);
            if (k == 2 && !_isVisited[i][j][3]) dfs(i, j, 3);
            if (k == 3 && !_isVisited[i][j][2]) dfs(i, j, 2);
        }

        if (k == 0) {
            if (i - 1 >= 0 && !_isVisited[i-1][j][2]) dfs(i - 1, j, 2);
        } else if (k == 1) {
            if (j + 1 < _n && !_isVisited[i][j+1][3]) dfs(i, j + 1, 3);
        } else if (k == 2) {
            if (i + 1 < _n && !_isVisited[i+1][j][0]) dfs(i+1, j, 0);
        } else if (k == 3) {
            if (j - 1 >= 0 && !_isVisited[i][j-1][1]) dfs(i, j - 1, 1);
        }
    }

public:
    /* 把每一个小方块分成四个小三角形 */ 
    int regionsBySlashes(vector<string>& grid) {
        _grid = grid;
        _n = grid.size();

        _isVisited.resize(_n, vector<vector<bool>>(_n, vector<bool>(4, false)));

        int count = 0;
        for (int i = 0; i < _n; ++i) {
            for (int j = 0; j < _n; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (!_isVisited[i][j][k]) {
                        dfs(i, j, k);
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

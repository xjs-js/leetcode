// https://leetcode-cn.com/problems/count-sub-islands/submissions/

class Solution {
private:
    int _m;
    int _n;
    vector<vector<bool>> _isVisited1;
    vector<vector<bool>> _isVisited2;
    
    unordered_map<int, set<pair<int, int>>> _dict1;
    unordered_map<int, set<pair<int, int>>> _dict2;
    vector<vector<int>> _grid2;
    
    vector<vector<int>> _subColor;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, unordered_map<int,set<pair<int, int>>>& dict, int i, int j, int color, bool isOne) {
        isVisited[i][j] = true;
        dict[color].insert({i, j});
        
        if (isOne) {
            if (_grid2[i][j] == 1) {
                _subColor[i][j] = color;
            }
        }
        
        
        int x[4] = {-1, 0, +1, 0};
        int y[4] = {0, +1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int i_x = i + x[k];
            int j_y = j + y[k];
            
            if (i_x >= 0 && i_x < _m && j_y >= 0 && j_y < _n) {
                if (grid[i_x][j_y] == 1 && !isVisited[i_x][j_y]) {
                    dfs(grid, isVisited, dict, i_x, j_y, color, isOne);
                    
                }
            }
        }
    }
    
    
public:
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        _grid2 = grid2;
        
        _m = grid1.size();
        _n = grid1[0].size();
        _isVisited1.resize(_m, vector<bool>(_n, false));
        _isVisited2.resize(_m, vector<bool>(_n, false));
        _subColor.resize(_m, vector<int>(_n, 0));
        
        int color = 1;
        int color_2 = 1;
        for (int i = 0; i < _m; ++i) {
            for (int j = 0; j < _n; ++j) {
                if (grid1[i][j] == 1 && !_isVisited1[i][j]) {
                    dfs(grid1, _isVisited1, _dict1, i, j, color, true);
                    ++color;
                }
                if (grid2[i][j] == 1 && !_isVisited2[i][j]) {
                    dfs(grid2, _isVisited2, _dict2, i, j, color_2, false);
                    ++color_2;
                }
            }
        }
        
        auto it = _dict2.begin();
        int relt = 0;
        while (it != _dict2.end()) {
            set<pair<int,int>>& st = it->second;
            auto it2 = st.begin();
           
            pair<int, int> f = *it2;

            if (_subColor[f.first][f.second] != 0) {
                int c = _subColor[f.first][f.second];
 
                bool isAll = true;
                 ++it2;
                while (it2 != st.end()) {
                    if (_subColor[(*it2).first][(*it2).second] != c) {
                        isAll = false;
                        break;
                    }
                    
                    ++it2;
                }
                if (isAll) {
                    ++relt;
                }
            }
            
            ++it;
        }
        return relt;
    }
};

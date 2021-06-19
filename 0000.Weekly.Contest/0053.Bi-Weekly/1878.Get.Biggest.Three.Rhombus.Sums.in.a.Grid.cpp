// https://leetcode-cn.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

class Solution {
public:
    int calc(vector<vector<int>>& grid, int i, int j, int k) {
        int len = k;
        int curRelt = 0;
        int m = grid.size(); int n = grid[0].size();
        while (len--) {
            ++i; ++j;
            if (0 <= i && i < m && 0 <= j && j < n) {
                curRelt += grid[i][j];
            } else {
                return -1;
            }
        }
        
        len = k;
        while (len--) {
            ++i; --j;
            if (0 <= i && i < m && 0 <= j && j < n) {
                curRelt += grid[i][j];
            } else {
                return -1;
            }
        }
        
        len = k;
        while (len--) {
            --i; --j;
            if (0 <= i && i < m && 0 <= j && j < n) {
                curRelt += grid[i][j];
            } else {
                return -1;
            }           
        }
        
        len = k;
        while (len--) {
            --i; ++j;
            if (0 <= i && i < m && 0 <= j && j < n) {
                curRelt += grid[i][j];
            } else {
                return -1;
            }           
        }
        
        return curRelt;
    }
    
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> relt;
        
        int m = grid.size(), n = grid[0].size();
        int len = (m-1) / 2;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                relt.insert(grid[i][j]);
            }
        }
        
        for (int k = 1; k <= len; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int curRelt = calc(grid, i, j, k);
                    if (curRelt != -1) {
                        relt.insert(curRelt);
                    }
                }
            }
        }
        
        
        
        vector<int> realRelt(relt.rbegin(), relt.rend());
        if (realRelt.size() > 3) {
            return {realRelt[0], realRelt[1], realRelt[2]};
        } else {
            return realRelt;
        }
    }
};
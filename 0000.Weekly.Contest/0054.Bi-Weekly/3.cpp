// https://leetcode-cn.com/problems/largest-magic-square/

class Solution {
public:
    bool isMatch(vector<vector<int>>& grid, int x, int y, int k) {
        int sum = -1;
        for (int i = x; i < x + k; ++i) {
            int curSum = 0;
            for (int j = y; j < y + k; ++j) {
                curSum += grid[i][j];
            }
            if (sum == -1) sum = curSum;
            else {
                if (sum != curSum) {
                    return false;
                }
            }
        }
        
        for (int j = y; j < y+k; ++j) {
            int curSum = 0;
            for (int i = x; i < x + k; ++i) {
                curSum += grid[i][j];
            }
            if (sum == -1) sum = curSum;
            else {
                if (sum != curSum) {
                    return false;
                }
            }
        }
        
        int curSum = 0;
        for (int i = 0; i < k; ++i) {
            curSum += grid[x+i][y+i];
        }
        if (curSum != sum) return false;
        
        curSum = 0;
        for (int i = 0; i < k; ++i) {
            curSum += grid[x+i][y+k-1-i];
        }
        if (curSum != sum) return false;
        return true;
    }
    
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        for (int k = min(m, n); k >= 2; --k) {
            for (int i = 0; i+k-1 < m; ++i) {
                for (int j = 0; j+k-1 < n; ++j) {
                    if (isMatch(grid, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        
        return 1;
    }
};

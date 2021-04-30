class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        unordered_set<int> memo;
        
        int sum = -1;
        for (int m = 0; m < 3; ++m) {
            int rowSum = 0;
            int colSum = 0;
            for (int n = 0; n < 3; ++n) {
                int num = grid[i+m][j+n];
                if (num < 1 || num > 9) {
                    return false;
                } else {
                    if (memo.count(num)) {
                        return false;
                    }
                    memo.insert(num);
                }
            
                rowSum += grid[i+m][j+n];
                colSum += grid[i+n][j+m];
            }

            if (rowSum != colSum) {
                return false;
            }
            if (sum == -1) {
                sum = rowSum;
            } else {
                if (sum != rowSum) {
                    return false;
                }   
            }
        }

        // diagonal
        int dia_1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int dia_2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        if (dia_1 != dia_2) {
            return false;
        }
        
        if (dia_1 != sum) {
            return false;
        }
        
        return true;
        
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int relt = 0;
        for (int i = 0; i <= row - 3; ++i) {
            for (int j = 0; j <= col - 3; ++j) {
                if (isMagic(grid, i, j)) {
                    ++relt;
                }
            }
        }
        return relt;
    }
};

/**
 * @date: 2021-04-15 21:04 Thur.
 */

class Solution {
public:
    bool isRowValid(vector<vector<char>>& board, int row) {
        unordered_set<char> memo;
        
        for (int i = 0; i < 9; ++i) {
            char c = board[row][i];
            if (c == '.') {
                continue;
            }
            
            if (memo.count(c)) {
                return false;
            }
            memo.insert(c);
        }
        
        return true;
    }
    
    bool isColValid(vector<vector<char>>&board, int col) {
        unordered_set<char> memo;
        
        for (int i = 0; i < 9; ++i) {
            char c = board[i][col];
            if (c == '.') {
                continue;
            }
            
            if (memo.count(c)) {
                return false;
            }
            memo.insert(c);
        }
        
        return true;
    }
    
    bool isSquareValid(vector<vector<char>>& board, int i, int j) {
        unordered_set<char> memo;
        
        for (int m = i; m < i+3; ++m) {
            for (int n = j; n < j + 3; ++n) {
                char c = board[m][n];
                if (c == '.') {
                    continue;
                }
                
                if (memo.count(c)) {
                    return false;
                }
                memo.insert(c);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < 9; ++i) {
            if (!isRowValid(board, i)) {
                return false;
            }
        }
        
        // check col
        for (int i = 0; i < 9; ++i) {
            if (!isColValid(board, i)) {
                return false;
            }
        }
        
        // check 9 of 3 * 3
        if (!isSquareValid(board, 0, 0) ||
           !isSquareValid(board, 0, 3) ||
           !isSquareValid(board, 0, 6) ||
           !isSquareValid(board, 3, 0) ||
           !isSquareValid(board, 3, 3) ||
           !isSquareValid(board, 3, 6) ||
           !isSquareValid(board, 6, 0) ||
           !isSquareValid(board, 6, 3) ||
           !isSquareValid(board, 6, 6)) {
            return false;
        }
        
        return true;
    }
};
/**
 * @date: 2021-04-18 23:09 Sun.
 */

class Solution {
private:
    bool _result;
public:
    void dfs(vector<vector<char>>& board, string word, int cur, int i, int j, bool** isVisit) {
        if (_result == true) {
            return ;
        } else {
            if (cur == word.size()) {
                _result = true;
                return ;
            }
            
            // up
            if (i - 1 >= 0 && board[i-1][j] == word[cur] && !isVisit[i-1][j]) {
                isVisit[i-1][j] = true;
                dfs(board, word, cur + 1, i - 1, j, isVisit);
                isVisit[i-1][j] = false;
            }
            
            // down
            if (!_result && i + 1 <= board.size()-1 && board[i+1][j] == word[cur] && !isVisit[i+1][j]) {
                isVisit[i+1][j] = true;
                dfs(board, word, cur + 1, i + 1, j, isVisit);
                isVisit[i+1][j] = false;
            }
            
            // left
            if (!_result && j - 1 >= 0 && board[i][j-1] == word[cur] && !isVisit[i][j-1]) {
                isVisit[i][j-1] = true;
                dfs(board, word, cur + 1, i, j-1, isVisit);
                isVisit[i][j-1] = false;
            }
            
            // right
            if (!_result && j + 1 <= board[0].size()-1 && board[i][j+1] == word[cur] && !isVisit[i][j+1]) {
                isVisit[i][j+1] = true;
                dfs(board, word, cur + 1, i, j + 1, isVisit);
                isVisit[i][j+1] = false;
            }
            
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        _result = false;
        int row = board.size();
        int col = board[0].size();
        
        bool** isVisit = new bool*[row];
        for (int i = 0; i < row; ++i) {
            isVisit[i] = new bool[col];
            for (int j = 0; j < col; ++j) {
                isVisit[i][j] = false;
            }
        }
        
        for (int i = 0; i < row && !_result; ++i) {
            for (int j = 0; j < col && !_result; ++j) {
                char c = board[i][j];
                if (c == word[0]) {
                    isVisit[i][j] = true;
                    dfs(board, word, 1, i, j, isVisit);
                    isVisit[i][j] = false;
                }
            }
        }
        
        return _result;
    }
};
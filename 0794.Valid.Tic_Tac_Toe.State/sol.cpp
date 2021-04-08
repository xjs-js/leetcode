/**
 * @date: 2021-04-06 20:35
 * @note: 简单，暴力就完事儿了
 */

#include "../headers.h"

class Solution {
private:
    bool judgeWin(const vector<string>& board, const char& player) {
        // 一共八条线，给👴上
        return (board[0][0] == player && board[0][1] == player && board[0][2] == player) ||         // 第一行
                (board[1][0] == player && board[1][1] == player && board[0][2] == player) ||        // 第二行
                (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||        // 第三行
                (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||        // 第一列
                (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||        // 第二列
                (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||        // 第三列
                (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||        // 对角线
                (board[2][0] == player && board[1][1] == player && board[0][2] == player);          // 对角线
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int num_X = 0, num_O = 0;
        bool win_X = false, win_O = false;

        // 统计数组中 X 和 O 的个数
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++num_X;
                } else if (board[i][j] == 'O') {
                    ++num_O;
                }
            }
        }

        win_X = judgeWin(board, 'X');
        win_O = judgeWin(board, 'O');

        if (num_X == num_O) {
            return !win_X;
        } else if (num_X == num_O + 1) {
            return !win_O;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> board {"OXX","XOX","OXO"};
    cout << boolalpha << solution.validTicTacToe(board) << endl;
    return 0;
}
/**
 * @date: 2021-04-08 17:04
 * @note: leetcode每日一题
 */

#include "../headers.h"

class Solution {
private:
    unordered_map<char, vector<char>> _dict;
    vector<string> _resultArr;
private:
    void dfs(const string& digits, int curIndex, string result) {
        int N = digits.size();
        if (curIndex == N) {
            _resultArr.emplace_back(result);
        } else {
            const char& curChar = digits[curIndex];
            vector<char>& alphas = _dict[curChar];

            string original = result;
            for (auto c : alphas) {
                dfs(digits, curIndex + 1, result + c);
            }
        }
    }

public:
    Solution() {
        _dict = {
            {'2', {'a', 'b', 'c'}}, 
            {'3', {'d', 'e', 'f'}}, 
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}};
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return _resultArr;
        }
        dfs(digits, 0, "");
        return _resultArr;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    string digits("23");

    auto result = sol.letterCombinations(digits);
    PrintArray(result);
    return 0;
}

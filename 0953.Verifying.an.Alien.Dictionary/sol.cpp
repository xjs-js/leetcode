/**
 * @date: 2021-04-09 16:55 Fri
 * @note: leetcode 每日一题
 * @name: 验证外星语词典
 * @url: https://leetcode-cn.com/problems/verifying-an-alien-dictionary/
 */

#include "../headers.h"

class Solution {
private:
    bool isOrdered(string& left, string& right, int* weight) {
        int M = left.size();
        int N = right.size();

        int i = 0;
        while (i < M && i < N) {
            if (weight[right[i]-'a'] > weight[left[i]-'a']) {
                return true;
            } else if (weight[right[i]-'a'] < weight[left[i]-'a']) {
                return false;
            }

            ++i;
        }

        return i == M;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        int* weight = new int[26];
        
        for (size_t i = 0; i < order.size(); ++i) {
            weight[order[i] - 'a'] = i;
        }

        for (size_t i = 1; i < words.size(); ++i) {
            string prev = words[i - 1];
            string curr = words[i];
            if (!isOrdered(prev, curr, weight)) {
                return false;
            }
        }

        delete[] weight;

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<string> words{"hello","leetcode"};
    string order("hlabcdefgijkmnopqrstuvwxyz");

    cout << boolalpha << sol.isAlienSorted(words, order) << endl;
    return 0;
}
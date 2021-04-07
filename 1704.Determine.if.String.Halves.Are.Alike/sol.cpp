/**
 * @date: 2021-04-07 21:26
 * @note: leetcode 每日一题
 * @note: 明天考科目一了，这题好简单，今天就写了两道
 */

class Solution {
private:
    int count(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            const char& c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                ++result;
        }
        return result;
    }
public:
    bool halvesAreAlike(string s) {
        int N = s.size();
        int half_N = N / 2;
        string left = s.substr(0, half_N);
        string right = s.substr(half_N);

        return count(left) == count(right);
    }
};

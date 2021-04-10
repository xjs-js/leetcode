/**
 * @date: 2021-04-10 13:33 Sat
 * @name: 匹配子序列的单词数
 * @url: Number of Matching Subsequences
 */

class Solution {
private:
    bool isSubseq(const string& s, const string& word) {
        int beg = 0;
        
        for (int i = 0; i < word.length(); ++i) {
            size_t end = s.find(word[i], beg);
            if (end == string::npos) {
                return false;
            }
            beg = end + 1;
        }

        return true;
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        for (string& word : words) {
            if (isSubseq(s, word)) {
                ++result;
            }
        }

        return result;
    }
};
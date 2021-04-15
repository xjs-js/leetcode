/**
 * @date: 2021-04-15 23:48 Thur.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            ++count[c];
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
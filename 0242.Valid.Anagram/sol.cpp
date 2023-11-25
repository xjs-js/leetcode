/**
 * @date: 2023/11/21 20:08 Tues
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s(26, 0);
        vector<int> count_t(26, 0);

        for (char c : s)    ++count_s[c - 'a'];
        for (char c : t)    ++count_t[c - 'a'];

        for (int i = 0; i < 26; ++i)
            if (count_s[i] != count_t[i])
                return false;
        
        return true;
    }
};

/**
 * @date: 2021-04-15 13:53 Thur.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

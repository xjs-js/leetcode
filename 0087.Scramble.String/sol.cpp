class Solution {
public:
    map<pair<string, string>, bool> memo;
    bool isS(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        if (s1.size() == 2) {
            return (s1[0] == s2[0] &&  s1[1] == s2[1]) || (s1[0] == s2[1] && s1[1] == s2[0]);
        }

        if (memo.find({s1, s2}) != memo.end()) {
            return memo[{s1, s2}];
        }

        int n = s1.size();
        for (int i = 1; i <= s1.size()-1; ++i) {
            // s1的前i个字符和s2的前i个字符 词频相同
            if (isLegal(s1, s2, i)) {
                if (isS(s1.substr(0, i), s2.substr(0, i)) && isS(s1.substr(i), s2.substr(i))) {
                    memo[{s1, s2}] = true;
                    return true;
                }
            }

            // s1的前i个字符和s2的后i个字符 词频相同
            if (isLegal2(s1, s2, i)) {
                if (isS(s1.substr(0, i), s2.substr(n-i)) && isS(s1.substr(i), s2.substr(0, n-i))) {
                    memo[{s1, s2}] = true;
                    return true;
                }
            }
        }

        memo[{s1, s2}] = false;
        return false;
    }

    // 判断词频是否相同， s1的前i个字符和s2的前i个字符 
    bool isLegal(string s1, string s2, int leftLen) {
        unordered_map<char, int> left_1;
        unordered_map<char, int> left_2;

        for (int i = 0; i < leftLen; ++i) {
            ++left_1[s1[i]];
            ++left_2[s2[i]];
        }

        auto it = left_1.begin();
        while (it != left_1.end()) {
            if (it->second != left_2[it->first]) {
                return false;
            }
            ++it;
        }

        return true;
    }

    // 判断词频是否相同， s1的前i个字符和s2的后i个字符 
    bool isLegal2(string s1, string s2, int leftLen) {
        unordered_map<char, int> left_1;
        unordered_map<char, int> left_2;
        int n = s1.size();
        for (int i = 0; i < leftLen; ++i) {
            ++left_1[s1[i]];
            ++left_2[s2[n-1-i]];
        }

        auto it = left_1.begin();
        while (it != left_1.end()) {
            if (it->second != left_2[it->first]) {
                return false;
            }
            ++it;
        }

        return true;
    }


    bool isScramble(string s1, string s2) {
        if (s1.size() == 1) {
            return s1 == s2;
        }
        string s1_copy(s1);
        string s2_copy(s2);

        sort(s1_copy.begin(), s1_copy.end());
        sort(s2_copy.begin(), s2_copy.end());

        // 判断s1和s2的词频
        if (s1_copy != s2_copy) {
            return false;
        }

        int n = s1.size();
        for (int i = 1; i <= n - 1; ++i) {
            if (isLegal(s1, s2, i)) {
                if (isS(s1.substr(0, i), s2.substr(0, i)) && isS(s1.substr(i), s2.substr(i))) {
                    return true;
                }
            }

            if (isLegal2(s1, s2, i)) {
                if (isS(s1.substr(0, i), s2.substr(n-i)) && isS(s1.substr(i), s2.substr(0, n-i))) {
                    return true;
                }
            }
        }

        return false;
    }
};
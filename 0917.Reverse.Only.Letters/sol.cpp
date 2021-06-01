class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = -1;
        int j = s.size();
        

        while (i < j) {
            do { ++i; } while (i < n && !isalpha(s[i]));
            do { --j; } while (j >= 0 && !isalpha(s[j]));

            if (i < j) swap(s[i], s[j]);
        }

        return s;
    }
};

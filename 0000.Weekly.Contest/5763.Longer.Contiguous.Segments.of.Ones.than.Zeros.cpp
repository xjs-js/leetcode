class Solution {
public:
    bool checkZeroOnes(string s) {
        int len_0 = 0;
        int len_1 = 0;
        
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') {
                    ++j;
                }
                len_0 = max(len_0, j - i);
                i = j;
            } else if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') {
                    ++j;
                }
                len_1 = max(len_1, j - i);
                i = j;
            }
        }
        
        return len_1 > len_0;
    }
};

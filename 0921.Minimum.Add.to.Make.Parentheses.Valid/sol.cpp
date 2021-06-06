class Solution {
public:
    // 栈
    int minAddToMakeValid(string s) {
        int n = s.size();
        int sk = 0;

        int relt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++sk;
            } else {
                if (sk == 0) {
                    ++relt;
                } else {
                    --sk;
                }
            }
        }
        relt += sk;

        return relt;
    }
};

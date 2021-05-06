class Solution {
public:
    bool isPalindrome(const string& s, int beg, int end) {
        int b = beg;
        int e = end;
        
        while (b <= e) {
            if (s[b] == s[e]) {
                ++b;
                --e;
            } else {
                return false;
            }
        }
        
        return true;
    }
    
    
    string longestPalindrome(string s) {
        int len = 1;
        string relt = s.substr(0, 1);
        
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+len; j < n; ++j) {
                if (isPalindrome(s, i, j) && j - i + 1> len) {
                    len = j - i + 1;
                    relt = s.substr(i, len);
                }    
            }
        }
        
        
        return relt;
    }
};

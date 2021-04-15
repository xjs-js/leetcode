/**
 * @date: 2021-04-16 00:04 Fri.
 */

class Solution {
public:
    bool isLegal(char c) {
        return isdigit(c) || isalpha(c);
    }
    
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return true;
        }
        
        
        int i = 0;
        int j = s.size() - 1;
        
        while (i < s.size() && !isLegal(s[i])) {
            ++i;
        }
        
        while (j < s.size() && !isLegal(s[j])) {
            --j;
        }
        
        while (i < j) {
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
            ++i; --j;
            while (i < s.size() && !isLegal(s[i])) {
                ++i;
            }
            
            while (j < s.size() && !isLegal(s[j])) {
                --j;
            }
        }
        
        return true;
    }
};
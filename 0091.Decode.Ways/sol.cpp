class Solution {
public:
    bool isValid(char c) {
        return (c >= '1' && c <= '9');
    }
    
    bool isValid(char c1, char c2) {
        if (c1 == '1') {
            return (c2 >= '0' && c2 <= '9');
        } else if (c1 == '2') {
            return (c2 >= '0' && c2 <= '6');
        }
        return false;
    }
    
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        
        if (s.size() == 1) {
            if (isValid(s[0])) {
                return 1;
            } else {
                return 0;
            }
        }
    
        int n = s.size();
        vector<int> dp(n);
        
        dp[0] = isValid(s[0]) ? 1 : 0;
        if (dp[0] == 0) {
            return 0;
        }
        
        dp[1] = 1;
        if (isValid(s[1]) && isValid(s[0], s[1])) {
            dp[1] = 2;
        } else if (!isValid(s[1]) && !isValid(s[0], s[1])) {
            return 0;
        } else {
            dp[1] = 1;
        }
        
        for (int i = 2; i < s.size(); ++i) {
            bool isSingle = isValid(s[i]);
            bool isPair = isValid(s[i-1], s[i]);
            
            if (isSingle && isPair)         dp[i] = dp[i-1] + dp[i-2];
            else if (isSingle && !isPair)   dp[i] = dp[i-1];
            else if (!isSingle && isPair)   dp[i] = dp[i-2];
            else                            return 0;
        }
        
        return dp[s.size() - 1];
    }
};
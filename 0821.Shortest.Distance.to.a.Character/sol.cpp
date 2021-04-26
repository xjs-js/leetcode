class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        
        vector<int> next(n+1, 10010);
        vector<int> prev(n+1, 10010);
        vector<int> relt(n);
        
        next[n] == 10010;
        for (int j = n-1; j >= 0; --j) {
            if (s[j] == c) {
                next[j] = j;
            } else {
                next[j] = next[j+1];
            }
        }
        
        if (s[0] == c) prev[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == c) {
                prev[i] = i;
            } else {
                prev[i] = prev[i-1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            relt[i] = min(abs(i-prev[i]), abs(next[i]-i));
        }
        
        return relt;
    }
};
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int m = encoded.size();
        int n = m + 1;
        vector<int> relt(n);
        
        int x = 0;
        for (int i = 1; i <= n; ++i) {
            x ^= i;
        }
        
        for (int i = 1; i < m; i += 2) {
            x ^= encoded[i];
        }
        
        relt[0] = x;
        
        for (int i = 1; i < n; ++i) {
            relt[i] = relt[i-1] ^ encoded[i-1];
        }
        
        return relt;
    }
};

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size() + 1;
        vector<int> relt(n, 0);
        
        relt[0] = first;
        for (int i = 1; i < n; ++i) {
            relt[i] = encoded[i-1] ^ relt[i-1];
        }
        return relt;
    }
};

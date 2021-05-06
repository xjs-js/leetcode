class Solution {
public:
    int xorOperation(int n, int start) {
        int relt = start + 2 * 0;
        
        for (int i = 1; i < n; ++i) {
            relt ^= (start + 2 * i);
        }
        
        return relt;
    }
};

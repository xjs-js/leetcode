#define MOD 10000000

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        uint64_t relt = 1;
        
        for (uint64_t i = 1; i <= n; ++i) {
            relt = (relt % MOD) * i % MOD;
            while (relt && relt % 10 == 0) {
                relt /= 10;
                ++count;
            }
        }
        
        return count;
    }
};

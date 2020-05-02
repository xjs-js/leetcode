#include <cstdint>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        uint64_t m_64 = m;
        uint64_t n_64 = n;
        if (m_64 == 0) {
            return 0;
        }
        if (m_64 * 2 <= n_64) {
            return 0;
        }
        int result = m;
        for (uint64_t i = m_64+1; i <= n_64; ++i)
            result = result & i;
        return result;
    }
};
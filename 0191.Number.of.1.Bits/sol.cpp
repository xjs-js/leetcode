class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            if (n & 0x01) {
                ++result;
            }
            n = n >> 1;
        }
        return result;
    }
};
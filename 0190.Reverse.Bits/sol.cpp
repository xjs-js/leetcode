#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int last_digit = n & 0x00000001;
            result = (result << 1) + last_digit;
            n = n >> 1;
        }

        return result;
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    std::cout << s.reverseBits(43261596) << std::endl;
    std::cout << s.reverseBits(4294967293) << std::endl; 
    return 0;
}
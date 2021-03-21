#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string origin = to_string(N);
        size_t len = origin.size();
        std::sort(origin.begin(), origin.end());

        int i = 0;
        while (true) {
            uint64_t num = pow(2, i++);
            string num_str = to_string(num);
            size_t len_after = num_str.size();
            if (len_after > len) {
                return false;
            } else if (len_after == len) {
                std::sort(num_str.begin(), num_str.end());

                if (num_str == origin) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main(int argc, char* argv[])
{
    Solution sol;
    std::cout << std::boolalpha << sol.reorderedPowerOf2(24) << std::endl;
    return 0;
}
#include <iostream>
#include <functional>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str_N = to_string(N);
        size_t len = str_N.size();
        vector<char> origin(len);
        vector<char> after(len);

        for (int i = 0; i < len; i++) {
            origin[i] = str_N[i];
        }
        std::sort(origin.begin(), origin.end());

        int i = 0;
        while (true) {
            uint64_t num = pow(2, i++);
            string num_str = to_string(num);
            size_t len_after = num_str.size();
            if (len_after > len) {
                return false;
            } else if (len_after == len) {
                for (int j = 0; j < len_after; ++j) {
                    after[j] = num_str[j];
                }

                std::sort(after.begin(), after.end());

                if (after == origin) {
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
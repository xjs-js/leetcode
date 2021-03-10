#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        size_t size = columnTitle.size();

        uint32_t result = 0;
        for (int i = size-1; i >= 0; --i) {
            char letter = columnTitle[i];
            result += (letter - 'A' + 1) * pow(26, size - 1 - i);
        }

        return result;
    }
};


int main(int argc, char* argv[])
{
    Solution sol;
    std::cout << sol.titleToNumber("A") << std::endl;
    std::cout << sol.titleToNumber("AB") << std::endl;
    std::cout << sol.titleToNumber("ZY") << std::endl;
    std::cout << sol.titleToNumber("FXSHRXW") << std::endl;
    return 0;
}
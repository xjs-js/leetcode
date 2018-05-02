#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) { // 12ms
        // int range: -2147483648 to 2147483647
        // int range: INT_MIN to INT_MAX (iostream)

        int sign = x < 0 ? -1 : 1;
        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());
        long relt = std::stol(s) * sign;
        return (relt > INT_MAX || relt < INT_MIN) ? 0 : relt;
    }

    int reverse2(int x) { // 9ms
        long relt = 0;
        while (x) {
            relt = relt * 10 + x % 10;
            x = x / 10;
        }
        return (relt > INT_MAX || relt < INT_MIN) ? 0 : relt;
    }
};

int main()
{
    cout << atoi("-9999") << endl;
}
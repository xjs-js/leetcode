#include <iostream>
#include <cmath>

using namespace std;

int fib_n(int n)
{
    double Phi = (1 + sqrt(5)) / 2.0;
    double phi = (1 - sqrt(5)) / 2.0;
    return (pow(Phi, n) - pow(phi, n)) / sqrt(5);
}


class Solution {
public:
    int climbStairs(int n) {
        return fib_n(n+1);
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    for (int i = 2; i <= 20; ++i) 
        std::cout << i << "=>" << fib_n(i+1) << " => " << sol.climbStairs(i) << std::endl;
    return 0;
}

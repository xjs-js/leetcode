#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int, int> memo;

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        for (size_t i = 0; i < coins.size(); ++i) {
            if (amount == coins[i])
                return 1;
        }

        if (memo.find(amount) != memo.end())
            return memo.at(amount);

        bool isFind = false;
        int result = 0x7fffffff;
        for (size_t i = 0; i < coins.size(); ++i) {
            if (amount < coins[i])
                continue;

            int subResult = coinChange(coins, amount-coins[i]) + 1;
            if (subResult == 0)
                continue;
            if (subResult < result) {
                isFind = true;
                result = subResult;
            }
        }

        if (isFind) {
            memo.insert(std::make_pair(amount, result));
            return result;
        }

        else {
            memo.insert(std::make_pair(amount, -1));
            return -1;
        }


    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> test1({1,2,5});
    std::cout << sol.coinChange(test1, 11) << std::endl;

    return 0;
}
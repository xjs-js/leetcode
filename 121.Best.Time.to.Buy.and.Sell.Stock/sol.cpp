// 2017-05-29

#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    // very stupid
    static int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int max_profit = 0;

        int i = 0;
        int *dp = new int[N];

        while (i < N - 1) {
            while(prices[i] >= prices[i+1]) {
                i += 1;
                if (i == N - 1)
                    return max_profit;
            }
            dp[i] = 0;
            for (size_t j = i+1; j < N; j++)
                dp[j] = max(dp[j-1], prices[j]- prices[i]);
            max_profit = max(max_profit, dp[N-1]);
            i += 1;
        }

        return max_profit;
    }

};

int main() {
    vector<int> prices({7, 6, 9, 3, 1});
    cout << Solution::maxProfit(prices) << endl;
    return 0;
}
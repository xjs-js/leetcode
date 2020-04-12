class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        if (prices.size() < 2) {
            return profit;
        }

        for (size_t i = 1; i < prices.size(); ++i) {
            int today = prices[i];
            int yesterday = prices[i-1];

            if (today > yesterday)
                profit += (today - yesterday);
        }

        return profit;

    }
};
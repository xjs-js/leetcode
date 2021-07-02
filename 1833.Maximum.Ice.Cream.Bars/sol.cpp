class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int relt = 0;
        for (int i = 0; i < costs.size(); ++i) {
            if (costs[i] <= coins) {
                ++relt;
                coins -= costs[i];
            } else {
                break;
            }
        }

        return relt;
    }
};

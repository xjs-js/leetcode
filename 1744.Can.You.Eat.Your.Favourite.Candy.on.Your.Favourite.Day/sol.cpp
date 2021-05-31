class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> relt;

        // prefix sum
        vector<int64_t> prefixSum(candiesCount.size(), 0);
        prefixSum[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); ++i) {
            prefixSum[i] = prefixSum[i-1] + candiesCount[i];
        }

        for (auto& v : queries) {
            int favoriteType = v[0];
            int favoriteDay = v[1];
            int dailyCap = v[2];   

            // 余粮, 最大消耗速度, 最小消耗速度
            double avail = favoriteType == 0 ? 0 : prefixSum[favoriteType-1];
            double maxConsume = 1.0 * dailyCap * favoriteDay;
            double minConsume = 1.0 * favoriteDay;
            
            // cout << avail << endl;
            // cout << maxConsume << endl;
            // cout << minConsume << endl;
            // cout << candiesCount[85] << endl;
            if (minConsume <= avail + candiesCount[favoriteType] - 1 &&
            avail - (dailyCap - 1) <= maxConsume) {
                relt.push_back(true);
            } else {
                relt.push_back(false);
            }


        }
        return relt;
    }
};

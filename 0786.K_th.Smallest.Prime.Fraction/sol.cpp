/**
 * @date: 2021-04-10 18:32
 * @name: 第 K 个最小的素数分数
 * @url: https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/
 */

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<double> div;
        for (int i = 0; i < arr.size()-1; ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                double r = arr[i] * 1.0 / arr[j];
                div.emplace_back(r);
            }
        }
        sort(div.begin(), div.end());
        double target = div[k - 1];

        for (int i = 0; i < arr.size()-1; ++i) {
            for (int j = i + 1; j < arr.size(); ++j) {
                double r = arr[i] * 1.0 / arr[j];
                if (abs(target - r) < 1e-10) {
                    return {arr[i], arr[j]};
                }
            }
        }

        return {0,1};
    }
};

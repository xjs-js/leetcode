// 2023-11-20
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;

        int maxRelt = nums[0];
        int preRelt = nums[0];
        for (int i = 1; i < N; ++i) {
            int curNum = nums[i];

            if (preRelt + curNum > curNum) {
                preRelt = preRelt + curNum;
            } else {
                preRelt = curNum;
            }

            maxRelt = max(maxRelt, preRelt);
        }
        return maxRelt;
    }
};

#include <bits/stdc++.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, best = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum+nums[i]);
            best = max(best, sum);
        }
        return best;
    }
};

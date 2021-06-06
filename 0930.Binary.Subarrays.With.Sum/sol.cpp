class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 前缀和 + 哈希
        int n = nums.size();
        int preSum[n];
        memset(preSum, 0, sizeof preSum);

        int relt = 0;
        unordered_map<int, int> count;
        preSum[0] = nums[0];
        if (nums[0] == goal) ++relt;
        ++count[nums[0]];

        for (int i = 1; i < n; ++i) {
            preSum[i] = nums[i] + preSum[i-1];
            if (preSum[i] == goal) {
                ++relt;
            }

            if (preSum[i] >= goal) {
                int delta = preSum[i] - goal;
                relt += count[delta];
            }
            ++count[preSum[i]];
        }

        return relt;
    }
};

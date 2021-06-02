class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 前缀和
        vector<int> prefixSum(nums.size(), 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int relt = 0;
        map<int, int> delta; // 相差的值和下标

        for (int i = 0; i < nums.size(); ++i) {
            int nums_1 = prefixSum[i];
            int nums_0 = i + 1 - nums_1;
            
            if (nums_0 == nums_1) {
                relt = i + 1;
            } else {
                if (delta.find(nums_1 - nums_0) != delta.end()) {
                    int j = delta[nums_1 - nums_0];
                    relt = max(relt, i - j);
                } else {
                    delta[nums_1 - nums_0] = i;
                }
            
            }
        }

        return relt;
    }
};

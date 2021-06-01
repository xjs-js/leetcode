class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftMax[n];
        int rightMin[n];
        memset(leftMax, 0, sizeof leftMax);
        memset(rightMin, 0, sizeof rightMin);

        rightMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            rightMin[i] = min(nums[i], rightMin[i+1]);
        }

        for (int i = 0; i < n - 1; ++i) {
            if (i == 0) {
                leftMax[i] = nums[i];
            } else {
                leftMax[i] = max(leftMax[i-1], nums[i]);
            }

            if (leftMax[i] <= rightMin[i+1] ) {
                return i+1;
            }
        }

        return 0;
    }
};

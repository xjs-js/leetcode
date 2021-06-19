// https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int relt = 0;
        for (int i = 0; i < n / 2; ++i) {
            relt = max(relt, nums[i] + nums[n-1-i]);
        }
        return relt;
    }
};
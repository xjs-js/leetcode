class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0;
        while (i < nums.size() - 1 ) {
            if (nums[i] <= nums[i+1]) {
                ++i;
            } else {
                return i;
            }
        }
        return i;
    }
};
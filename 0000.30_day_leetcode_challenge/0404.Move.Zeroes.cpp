class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int* copyNums = new int[nums.size()];
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                copyNums[j++] = nums[i];
            }
            nums[i] = 0;
        }
        for (int i = 0; i < j; ++i) {
            nums[i] = copyNums[i];
        }
    }
};
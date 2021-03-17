/**
 * @date: 2021-03-18
 * @url: https://leetcode.com/problems/remove-element/
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        while (j >= 0 && nums[j] == val) {
            --j;
        }
        if (j < 0) {
            nums.erase(nums.begin(), nums.end());
        }
        else {
            while (i < j) {
                if (nums[i] == val) {
                    swap(nums[i], nums[j]);
                    while (j >= 0 && nums[j] == val) {
                        --j;
                    }
                } else {
                    ++i;
                }
            }
        }
        
        if (j != nums.size() - 1) {
            nums.erase(nums.begin() + j + 1, nums.end());
        }
        
        return nums.size();
    }
};
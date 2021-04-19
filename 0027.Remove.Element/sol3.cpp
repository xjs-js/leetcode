/**
 * @date: 2021-04-19 Mon. 19:00
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        
        return count;
    }
};
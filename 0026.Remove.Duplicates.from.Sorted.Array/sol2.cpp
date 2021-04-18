/**
 * @date: 2021-04-18
 */

class Solution {
public:
    int findNext(vector<int>& nums, int prev, int beg) {
        
        for (int i = beg; i < nums.size(); ++i) {
            if (nums[i] > prev) {
                return i;
            }
        }
        
        return nums.size();
    }
    
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return nums.size();
        }
        
        int count = 1;
        int prev = nums[0];
        
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] > prev) {
                prev = nums[i];
                ++i;
                ++count;
            } else {
                i = findNext(nums, prev, i+1);
                if (i != nums.size()) {
                    swap(nums[count], nums[i]);
                    prev = nums[count];
                    ++count;
                }
            }
        }
        return count;
    }
};
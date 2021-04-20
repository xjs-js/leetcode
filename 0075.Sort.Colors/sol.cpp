class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end = nums.size() - 1;
        
        int count = 0;
        while (count < nums.size() && nums[count] == 0) {
            ++count;
        }
        
        while (end > count) {
            if (nums[end] == 0) {
                swap(nums[count++], nums[end]);
                while (count < nums.size() && nums[count] == 0) {
                    ++count;
                }
            }
            --end;
        }
        
        while (count < nums.size() && nums[count] == 1) {
            ++count;
        }
        end = nums.size() - 1;
        while (end > count) {
            if (nums[end] == 1) {
                swap(nums[count++], nums[end]);
                while (count < nums.size() && nums[count] == 1) {
                    ++count;
                }
            }
            --end;
        }
        
    }
};
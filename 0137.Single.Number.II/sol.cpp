class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int n = nums.size();
        while (i+2 < n ) {            
            if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                i += 3;
            } else {
                return nums[i];
            }
        }
        
        return nums[i];
    }
};

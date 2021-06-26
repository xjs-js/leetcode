class Solution {
public:
    
    bool isValid(vector<int>& nums, int mid) {
       if (mid == 0) {
           for (int i = 2; i < nums.size(); ++i) {
               if (nums[i] <= nums[i-1]) {
                   return false;
               }
           }
           return true;
       } else {
           for (int i = 1; i < mid; ++i) {
               if (nums[i] <= nums[i-1]) {
                   return false;
               }
           }
           if (mid + 1 < nums.size()) {
               if (nums[mid+1] <= nums[mid-1]) {
                   return false;
               }
               
               for (int i = mid+2; i < nums.size(); ++i) {
                   if (nums[i] <= nums[i-1]) {
                       return false;
                   }
               }
           }
       }
        
        return true;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (isValid(nums, i)) {
                return true;
            }
        }
        
        return false;
    }
};
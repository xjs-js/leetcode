class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        memo[nums[0] % k] = 0;
        int sum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum % k == 0) {
                return true;
            }
            
            int curRemain = sum % k;
            if (memo.find(curRemain) != memo.end()) {
                int prevIndex = memo[curRemain];
                if (curRemain == 0) {
                    return true;
                }
                if (prevIndex < i - 1) {
                    return true;
                }
            } else {
                memo[curRemain] = i;
            }
        }
        
        
        
        return false;
    }
};
class Solution {
public:
    bool judge(vector<int>& nums, function<bool(int,int)> func) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (func(nums[i], nums[i-1])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
        return judge(nums, [](int lhs, int rhs) {
            return lhs <= rhs;
        }) || judge(nums, [](int lhs, int rhs) {
            return lhs >= rhs;
        });
    }
};

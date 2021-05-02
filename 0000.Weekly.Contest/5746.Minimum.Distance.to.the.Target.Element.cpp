class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int relt = 1e9;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                relt = min(relt, abs(i-start));
            }
        }
        return relt;
    }
};

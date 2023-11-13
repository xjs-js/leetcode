class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N = (int)nums.size();
        int relt = nums[0];
        for (int i = 1; i < N; ++i) {
            relt ^= nums[i];
        }
        return relt;
    }
};

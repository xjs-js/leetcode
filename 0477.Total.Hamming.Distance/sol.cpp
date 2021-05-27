class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int i = 0;
        int relt = 0;
        for (int i = 0; i < 32; ++i) {
            int count_0 = 0, count_1 = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (((nums[j] >> i) & 0x01) == 0) {
                    ++count_0;
                } else {
                    ++count_1;
                }
            }
            relt += (count_0 * count_1);
        }
        return relt;
    }
};

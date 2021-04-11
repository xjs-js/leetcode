/**
 * @date: 2021-04-11 Sun.
 */

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num_neg = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                return 0;
            } else if (nums[i] < 0) {
                ++num_neg;
            }
        }

        if (num_neg == 0 || num_neg % 2 == 0) {
            return 1;
        } else {
            return -1;
        }

        return 1;
    }
};
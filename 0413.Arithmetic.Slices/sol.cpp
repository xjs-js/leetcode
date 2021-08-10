class Solution {
public:
    int combine(int n) {
        if (n < 3) {
            return 0;
        } else {
            return (n - 1) * (n - 2) / 2;
        }
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int relt = 0;

        int start = 0;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i-1] != nums[i-1] - nums[i-2]) {
                int n = i - start;
                relt += combine(n);
                start = i - 1;
            }
        }
        if (start != nums.size() - 2) {
            relt += combine((int)nums.size() - start);
        }
        return relt;
    }
};

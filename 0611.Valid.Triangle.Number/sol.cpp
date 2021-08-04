class Solution {
public:
    int calc(vector<int>& nums, int i, int j) {
        if (nums[i] == 0 || nums[j] == 0) {
            return 0;
        }

        int target = nums[i] + nums[j];
        int l = j + 1; int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[r] < target) {
            return r - j;
        } else {
            return 0;
        }
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                count += calc(nums, i, j);

            }
        }
        return count;
    }
};

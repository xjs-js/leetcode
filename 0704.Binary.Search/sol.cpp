/**
 * @date: 2024-01-18 Thur.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (l < nums.size() && nums[l] == target) {
            return r;
        }
        if (r >= 0 && nums[r] == target) {
            return r;
        }

        return -1;
    }
};
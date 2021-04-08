/**
 * @date: 2021-04-08 16:13
 * @note: 考玩科目一回来了，合格了
 */

#include "../headers.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) {
            return nums[0];
        } else if (N == 2) {
            return min(nums[0], nums[1]);
        }

        int beg = 0;
        int end = N-1;
        int result = 5000;
        while (beg <= end) {
            if (end - beg == 1) {
                return min(nums[beg], nums[end]);
            }
            int firstNum = nums[beg];
            int lastNum = nums[end];
            int mid = (beg + end) / 2;
            int midNum = nums[mid];

            if (firstNum < lastNum) {
                return firstNum;
            } else {    // firstNum > lastNum
                if (midNum < lastNum) {
                    if (midNum < nums[mid-1]) {
                        return midNum;
                    } else {
                        end = mid - 1;
                    }
                } else if (midNum > firstNum) {
                    if (midNum > nums[mid+1]) {
                        return nums[mid+1];
                    } else {
                        beg = mid + 1;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    vector<int> nums{2,3,1};
    cout << sol.findMin(nums) << endl;
    return 0;
}
/**
 * @date: 2021-04-07 12:33
 * @note: 写完吃午饭
 */

#include "../headers.h"

class Solution {
public:

    /**
     * 在有序的列表中搜索目标肯定是用二分搜索
     *
     * @param nums
     * @param target
     * @return
     */
    bool search(vector<int>& nums, int target) {
        int N = nums.size();
        if (N == 1) {
            return nums[0] == target;
        }
        // 初始化beg和end指针
        int beg = 0;
        int end = N-1;

        while (beg <= end) {
            // 数组的第一个数
            int firstNum = nums[beg];
            int mid = (beg + end) / 2;
            // 中间的数
            int midNum = nums[mid];

            // 直接判断是否相等
            if (firstNum == target || midNum == target || nums[end] == target) {
                return true;
            }
            
            if (firstNum > midNum) { // 左边有下降的地方
                if (target < midNum) {   // target < midNum < firstNum
                    end = mid - 1;       // search left
                } else {
                    if (target > firstNum) {    // target > firstNum > midNum
                        end = mid - 1;          // search left
                    } else {                    // firstNum > target > midNum
                        beg = mid + 1;          // search right
                    }
                }
            } else if (firstNum < midNum) { // 右边有下降的地方
                if (midNum < target) {      // firstNum < midNum < target
                    beg = mid + 1;          // search right
                } else {        // target < midNum
                    if (target > firstNum) {    // firstNum < target < midNum
                        end = mid - 1;          // search left
                    } else {                    // target < midNum < firstNum
                        beg = mid + 1;          // search right
                    }
                }
            } else if (firstNum == midNum) {
                beg  = beg + 1;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums{3,5,1};
    int target = 1;
    Solution sol;
    cout << boolalpha << sol.search(nums, target) << endl;
    return 0;
}
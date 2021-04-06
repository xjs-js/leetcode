/**
 * @date: 2021-04-06 11:59
 * @note: 力扣每日一题
 */

class Solution {
    /**
     * 从beg+1开始到N结束，寻找第一个大于nums[beg]的下标
     *
     * @param nums 数组
     * @param N    数组的有效长度
     * @param beg  比较的目标下标
     * @return 返回在数组的有效长度下，第一个大于nums[beg]的下标，没有则返回N
     */
    int getNextIndex(vector<int>& nums, int N, int beg) {
        int next = beg + 1;
        bool isFind = false;
        for (; next < N; ++next) {
            if (nums[next] > nums[beg]) {
                isFind = true;
                break;
            }
        }

        if (isFind) {
            return next;
        }

        return N;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        
        int beg = 0;
        do {
            int next = getNextIndex(nums, N, beg);
            // 和nums[beg]相同的个数
            int beg_num = next - beg;
            if (beg_num > 2) {
                beg_num -= 2;
                // 删除
                for (int i = next; i < N; ++i) {
                    nums[i-beg_num] = nums[i];
                }
                N -= beg_num;

                beg += 2;
            } else {
                beg += 1;
            }
        } while (beg != N);

        return N;
    }
};

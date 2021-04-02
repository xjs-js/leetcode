/**
 * @date: 2021-04-02 15:17
 * @note: 真的是最后一题了。。。不，英文区的每日一题应该出来了
 */

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i <= N; ++i) {
            int num = N - i;

            if (i == 0) {
                if (num <= nums[0]) {
                    return num;
                }
            }
            else if (i == N) {
                if (num > nums[N-1]) {
                    return num;
                }
            }
            else {
                if (num > nums[i-1] && num <= nums[i]) {
                    return num;
                }
            }
        }

        return -1;
    }
};

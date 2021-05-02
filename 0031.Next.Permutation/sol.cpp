class Solution {
public:
    /**
     * 从后向前枚举nums[j], 在前面寻找是否有小于nums[j]的数nums[i]
     * 一定要靠后
     * 将 nums[j] 放到 nums[i] 上
     * nums[i+1] 到 最后 排序
     */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 最终的正序列对
        int last_i = -1, final_j = -1;

        for (int j = n-1; j >= 1; --j) {
            // 如果j比last_i还要小，如果对应的i存在，则i<j，则 i < last_i 
            // 故可以跳过
            if (j <= last_i) {
                break;
            }
            // 找到当前j对应的i
            for (int i = j-1; i >= 0; --i) {
                if (nums[j] > nums[i]) {
                    if (i > last_i) {
                        last_i = i;
                        final_j = j;
                        // i 就不需要再找了
                        break;
                    }
                }
            }
        }
        
        // 有值
        if (final_j != -1) {
            // 交换
            swap(nums[last_i], nums[final_j]);
            // 逆序
            reverse(nums.begin() + last_i +1 , nums.end());
        } else {
            // 逆序
            reverse(nums.begin(), nums.end());
        }
        

    }
};

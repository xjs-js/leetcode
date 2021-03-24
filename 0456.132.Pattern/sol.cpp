/**
 * @date: 2021-03-24
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        // newNums中的个数至少有三个
        if (N < 3) {
            return false;
        }

        vector<int> indexArr;   // 是峰的下标
        for (int j = 1; j < N-1; ++j) {
            if (nums[j] >= nums[j-1] && nums[j] >= nums[j+1]) {
                indexArr.emplace_back(j);
            }
        }
        
        // indexArr中的个数应该不为空
        if (indexArr.size() == 0) {
            return false;
        }
        
        // min_num[i] 表示[0, i)中最小的值
        vector<int> min_num(N, 0);

        // 构造min_num数组
        min_num[1] = nums[0];
        for (int i = 2; i < N; ++i) {
            min_num[i] = min(min_num[i-1], nums[i-1]);
        }

        // 遍历峰值
        for (int i = 0; i < indexArr.size(); ++i) {
            int index = indexArr[i];

            int middleNum = nums[index];
            int leftMin = min_num[index];

            for (int j = index + 1; j < N; ++j) {
                int righNum = nums[j];
                if (leftMin < righNum && righNum < middleNum) {
                    return true;
                }
            }

        }

        return false;
    }
};

int main(int argc, char* argv[])
{

    Solution sol;
    vector<int> nums_1{1,2,3,4};
    std::cout << std::boolalpha << sol.find132pattern(nums_1) << std::endl;
    vector<int> nums_2{3,1,4,2};
    std::cout << std::boolalpha << sol.find132pattern(nums_2) << std::endl;
    vector<int> nums_3{-1,3,2,0};
    std::cout << std::boolalpha << sol.find132pattern(nums_3) << std::endl;
    vector<int> nums_4{1,0,1,-4,-3};
    std::cout << std::boolalpha << sol.find132pattern(nums_4) << std::endl;
    vector<int> nums_5{1,3,2,4,5,6,7,8,9,10};
    std::cout << std::boolalpha << sol.find132pattern(nums_5) << std::endl;
    return 0;
}
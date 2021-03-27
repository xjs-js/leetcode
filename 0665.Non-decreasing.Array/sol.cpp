#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size();
        if (N <= 2) {
            return true;
        } else {
            bool hasDown = false;
            for (size_t i = 0; i < N-1; ++i) {
                if (nums[i] > nums[i+1]) {
                    if (hasDown) {
                        return false;
                    } else {
                        // 有下坡
                        hasDown = true;
                        if (i != 0) {
                            if (nums[i-1] <= nums[i+1]) {
                                // 把nums[i]往下压
                                continue;
                            } else {
                                if (i == N-2) {
                                    continue;
                                } else if (nums[i] > nums[i+2]) {
                                    // 把nums[i+1]往上顶
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    std::vector<int> nums_1{3,4,2,3};
    std::cout << std::boolalpha << sol.checkPossibility(nums_1) << std::endl; // false

    std::vector<int> nums_2{5,7,1,8};
    std::cout << std::boolalpha << sol.checkPossibility(nums_2) << std::endl; // true

    return 0;
}
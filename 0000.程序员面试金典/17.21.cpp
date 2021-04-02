/**
 * @date: 2021-04-02
 * @note: 虽然这是一道hard题目，但是我觉得是medium
 * @follow-up: 一开始写错了，但最后还是写出来了
 */

#include "../headers.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if (N <= 2) {
            return 0;
        }

        int* left_max = new int[N];
        int* right_max = new int[N];

        left_max[1] = height[0];
        for (int i = 2; i < N; ++i) {
            left_max[i] = max(left_max[i-1], height[i-1]); 
        }

        right_max[N-2] = height[N-1];
        for (int i = N-3; i >= 0; --i) {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }

        int result = 0;

        for (int i = 1; i < N - 1; ++i) {
            int low = min(left_max[i], right_max[i]);
            if (height[i] < low) {
                result += (low - height[i]);
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> nums{5,2,1,2,1,5};
    cout << sol.trap(nums) << endl;

    return 0;
}

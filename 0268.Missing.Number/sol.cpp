// 2017-05-29

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int missingNumber(vector<int>& nums) {
        int N = nums.size();

        int s = 0;
        for (size_t i = 0; i < N; i++)
            s += nums[i];

        return (1 + N) * N / 2 - s;
    }
};

int main() {
    vector<int> nums({0, 1});
    cout << Solution::missingNumber(nums) << endl;
}
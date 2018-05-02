// 2017-5-29

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (target <= nums[i])
                return i;
        }
        return nums.size();
    }
};

int main() {
    vector<int> nums({1, 3, 5, 6});

    cout << Solution::searchInsert(nums, 0) << endl;
}


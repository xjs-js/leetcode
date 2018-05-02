// 2017-5-30

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy_nums;
        copy_nums.assign(nums.begin(), nums.end());

        sort(copy_nums.begin(), copy_nums.end());

        int i, j;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != copy_nums[i]) {
                break;
            } 
        }
        if (i == nums.size()) return 0;

        for (j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] != copy_nums[j]) {
                break;
            }
        }

        return j - i + 1;
    }
};

int main() {
    vector<int> nums({1,2,4,5,3});

    cout << Solution::findUnsortedSubarray(nums) << endl;

    return 0;
}
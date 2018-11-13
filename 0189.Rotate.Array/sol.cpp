// 2018-11-13

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while (k--) {
            int last = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), last);
        }
    }
};


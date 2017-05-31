// 2017-5-31

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> hashMap;

        int x;
        for (int i = 0; i < nums.size(); i++) {
            x = nums[i];
            if (hashMap[x] != 0 && abs(i + 1 - hashMap[x]) <= k) 
                return true;
            hashMap[x] = i + 1;
        }

        return false;
    }

};

int main () {
    vector<int> nums({1, 1});

    cout << Solution::containsNearbyDuplicate(nums, 1) << endl;
}
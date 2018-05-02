// 2017-05-29

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        int max_times = -1;
        map<int, int> hashMap;
        
        for (int n : nums) {
            ++hashMap[n];
            if (hashMap[n] > nums.size() / 2)
                return n;
        }
    }
};


int main() {
    vector<int> nums({ 1,1,1,2,3 });
    cout << Solution::majorityElement(nums) << endl;
    return 0;
}
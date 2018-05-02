// 2017-05-29

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            } 
            else it++;

        }
        return nums.size();
    }
};

int main() {
    vector<int> nums({1});
    cout << Solution::removeElement(nums, 1) << endl;
    return 0;
}
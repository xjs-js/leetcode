// 2017-5-31

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int before = nums[0];
        for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ) {
            if (*it == before) {
                it = nums.erase(it);
            } else {
                before = *it;
                it++;
            }
        }

        return nums.size();
    }
    static void print(vector<int> nums) {
        for(vector<int>::iterator it = nums.begin(); 
                it != nums.end();
                it++)
            cout << *it << ' ';
        cout << endl;
    }
};

int main() {
    vector<int> nums({1,1,2});

    Solution::removeDuplicates(nums);

    Solution::print(nums);
}
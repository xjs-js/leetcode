// 2017-05-29

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;

        int N = nums.size();

        for (i = 0; i < N; i++) {
            if (nums[i] != 0)
                nums[j++] = nums[i];
        }

        while (j < N)
            nums[j++] = 0;
    }

    static void print(const vector<int>& nums) {
        for (int i : nums) {
            cout << i << ' ';
        }
        cout << endl;
    }
};


int main() {
    vector<int> nums;
    int n, t;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    
    Solution::moveZeroes(nums);

    Solution::print(nums);
}
// 2017-6-1

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int binarySearch(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (nums[mid] == target) return mid;
            if (nums[mid] < target)  lo = mid + 1;
            if (nums[mid] > target)  hi = mid - 1;
        }

        return -1;
    }

    static vector<int> searchRange(vector<int>& nums, int target) {
	    // init
        int n = nums.size();
        vector<int> ans;

        // binary search
        int index = binarySearch(nums, target);

        // switch index
        if (index == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            // to left
            int low = index - 1;
            while (low >= 0 && nums[low] == target)
                --low;
            ++low;
    
            int high = index + 1;
            while (high <= n - 1 && nums[high] == target)
                ++high;
            --high;
            
            ans.push_back(low);
            ans.push_back(high);
        }

        return ans;
    }
};

int main() {
    vector<int> nums({5, 7, 7, 8, 8, 10});

    vector<int> ans = Solution::searchRange(nums, 8);

    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << *it << ' ';
    cout << endl;
}
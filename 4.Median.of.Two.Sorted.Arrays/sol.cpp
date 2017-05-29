#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { // 79ms
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector<int> nums(m + n);

        for (int k = 0; k < m + n; k++) {
            if (j == n)                   nums[k] = nums1[i++];
            else if (i == m)              nums[k] = nums2[j++];
            else if (nums1[i] < nums2[j]) nums[k] = nums1[i++];
            else                          nums[k] = nums2[j++];
        }

        /*for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
            cout << *it << endl;*/

        if ((m + n) % 2 == 0) return (nums[(m + n) / 2] + nums[(m + n) / 2 - 1]) / 2.0;
        else                  return nums[(m + n) / 2];
    }
    
};

int main()
{
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}
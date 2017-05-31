// 2017-5-31

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;

        int i = m-1, j = n-1;
        int k = m+n-1;
        while (i > -1 && j > -1) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (i > -1) nums1[k--] = nums1[i--];
        while (j > -1) nums1[k--] = nums2[j--];

    }
};
// 2017-6-7

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int N = nums.size(), memo = -99999; // memo not set
        int cnt = 0;
        vector<int> nums_k;

        for (int i = 0; i < N; i++) {
            nums_k.push_back(nums[i] + k);
        }

        for (int i = 0; i < N; i++) {
            int cur = nums[i];
            int tar = nums_k[i];
            if (memo == -99999 || cur != memo) {
                for (int j = i + 1; j < N; j++) {
                    if (nums[j] == tar) {
                        cnt += 1;
                        memo = cur;
                        break;
                    }
                    if (nums[j] > tar) {
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};


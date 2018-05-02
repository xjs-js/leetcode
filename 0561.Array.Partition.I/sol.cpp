// 2017-05-29

#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int relt = 0;
        for (int i = 0; i < nums.size(); i += 2)
            relt += nums[i];
        return relt;
    }
};


int main() {
    vector<int> nums;
    Solution sol;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cout << sol.arrayPairSum(nums) << endl;
}
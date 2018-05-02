// 2017-05-29

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> relt;
        bool *has_appeared = new bool[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++)
            has_appeared[i] = false;

        for (int i = 0; i < nums.size(); i++) {
            if (has_appeared[nums[i]])
                relt.push_back(nums[i]);
            has_appeared[nums[i]] = true;
        }

        return relt;
    }
};


int main() {
    Solution s;
    int n, temp;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> ans = s.findDuplicates(nums);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}
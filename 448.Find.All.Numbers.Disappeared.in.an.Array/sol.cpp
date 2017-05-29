// 2017-05-29

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> relt;
        bool *has_appeared = new bool[N+1];
        
        for (size_t i = 1; i <= N; i++)
            has_appeared[i] = false;

        for (size_t i = 0; i < nums.size(); i++)
            has_appeared[nums[i]] = true;

        for (size_t i = 1; i <= N; i++) {
            if (!has_appeared[i])
                relt.push_back(i);
        }

        return relt;
    }
};

int main() {
    Solution s;
    int n, t;
    vector<int> nums;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        nums.push_back(t);
    }
    vector<int> ans = s.findDisappearedNumbers(nums);

    for (vector<int>::iterator it = ans.begin();
            it != ans.end();
            it++)
        cout << *it << ' ';

    cout << endl;

    return 0;
}
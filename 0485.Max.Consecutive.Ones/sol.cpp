// 2017-05-29

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_length = -1;
        int length = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (length > max_length)
                    max_length = length;
                length = 0;
            }
            else {
                ++length;
            }
        }
        max_length = max_length > length ? max_length : length;
        return max_length;
    }
};

int main() {
    Solution s;
    int n, temp;
    vector<int> nums;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    cout << s.findMaxConsecutiveOnes(nums) << endl;
    
    return 0;
}


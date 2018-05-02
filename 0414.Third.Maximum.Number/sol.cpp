// 2017-5-31

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int thirdMax1(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int ans;
        if (s.size() >= 3) {
            set<int>::reverse_iterator it = s.rbegin();
            it++;
            it++;
            ans = *it;
        } else {
            set<int>::reverse_iterator it = s.rbegin();
            ans = *it;
        }

        return ans;
    }

    static int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                nums[++j] = nums[i];
            if (j == 2) 
                return nums[2];
        }

        return nums[0];


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
    vector<int> nums({3,2,1});
    cout << Solution::thirdMax(nums) << endl;
}
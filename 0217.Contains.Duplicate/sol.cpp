// 2017-05-29


#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution {
public:
    static bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        
        for (int n : nums) {
            if (++counts[n] >= 2)
                return true;
        }
        
        return false;
    }
};

int main() {
    vector<int> nums({ 1,1,2 });
    cout << Solution::containsDuplicate(nums);
}
// 2023-11-20
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int & num : nums) {
            ++count[num];
            if (count[num] >= 2) {
                return true;
            }
        }

        return false;
    }
};


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

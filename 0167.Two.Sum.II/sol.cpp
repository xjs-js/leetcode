// 2017-05-29

#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // This solution is very very stupid!!!!
    static vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> hashMap;
        
        for (size_t i = 0; i < numbers.size(); i++) {
            hashMap[numbers[i]] = i + 1;
        }

        vector<int> relt;

        for (int n : numbers) {
            if (hashMap[target - n] != 0 && n != target - n) {
                relt.push_back(hashMap[n]);
                relt.push_back(hashMap[target- n]);
                break;
            }
            if (hashMap[target - n] != 0 && n == target - n) {
                relt.push_back(hashMap[n] - 1);
                relt.push_back(hashMap[n]);
                break;
            }
        }
        return relt;
    }

    static void print(vector<int> numbers) {
        for (vector<int>::iterator it = numbers.begin();
            it != numbers.end();
            it++)
            cout << *it << ' ';
        cout << endl;
    }
};

int main() {
    vector<int> numbers;
    int n, t;
    int target;
    cin >> n >> target;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        numbers.push_back(t);
    }

    vector<int> relt = Solution::twoSum(numbers, target);

    Solution::print(relt);

    return 0;
}
// 2017-05-30 
// Dragon Boat Festival today

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; i--) {
            int digit = digits[i];
            digits[i] = (carry + digits[i]) % 10;
            carry = (carry + digit) / 10;
            if (carry == 0)
                break;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};

int main() {
    vector<int> digits({9,9,9});

    vector<int> ans = Solution::plusOne(digits);

    for (vector<int>::iterator it = ans.begin(); 
            it != ans.end();
            it++)
        cout << *it << ' ';

    cout << endl;

    return 0;
}
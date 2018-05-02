#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);

        int N = str_x.size();
        for (int i = 0; i < N; i++) {
            if (str_x[i] != str_x[N-1-i])
                return false;
        }

        return true;
    }

};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.isPalindrome(x) << endl;
    return 0;
}

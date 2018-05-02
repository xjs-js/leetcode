// 2017-6-3

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        // init

        // new space
        vector<int> memo(n, 1);

        // walk through
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                memo[j] = memo[j-1] + memo[j];
        }

        // return answer
        return memo[n-1];
    }
};

int main() {
    cout << Solution::uniquePaths(2, 3) << endl;
}

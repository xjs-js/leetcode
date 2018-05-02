// 2017-5-30

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> relt;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp;

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)   temp.push_back(1);
                else                    temp.push_back(relt[i-1][j] + relt[i-1][j-1]);
            }

            relt.push_back(temp);
        }

        return relt;
    }
};

int main() {
    int numRows = 5;
    vector<vector<int>> ans = Solution::generate(numRows);

    for (int i = 0; i < numRows; i++) {
        for (vector<int>::iterator it = ans[i].begin(); it != ans[i].end(); it++)
            cout << *it << ' ';
        cout << endl;
    }

    return 0;
}
// 2017-5-30

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<int> getRow(int rowIndex) {
        vector<int> row_1({1});
        vector<int> row_2;

        for (int i = 1; i <= rowIndex; i++) {
            row_2.resize(i+1);

            row_2[0] = row_2[i] = 1;

            for (int j = 1; j <= i - 1; j++)
                row_2[j] = row_1[j-1] + row_1[j];

            row_1.assign(row_2.begin(), row_2.end());
        }

        return row_1;
    }
};

int main() {
    vector<int> row = Solution::getRow(3);

    for (vector<int>::iterator it = row.begin(); it != row.end(); it++)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
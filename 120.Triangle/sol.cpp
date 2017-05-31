// 2017-5-31

#include <bits/std++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();

        for (int i = rows - 2; i > -1; --i) {
            for (int j = 0; j < i + 1; j++) {
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }

        return triangle[0][0];
    }
};


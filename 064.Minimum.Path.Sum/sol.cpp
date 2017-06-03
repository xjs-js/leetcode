// 2017-6-3

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // init
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> relt;
        relt.swap(grid);

        // the first row
        for (int j = 1; j < cols; j++)
            relt[0][j] += relt[0][j - 1];

        // the first col
        for (int i = 1; i < rows; i++)
            relt[i][0] += relt[i-1][0];

        // the entire
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++)
                relt[i][j] += min(relt[i-1][j], relt[i][j-1]);
        }

        // return the answer
        return relt[rows-1][cols-1];
    }
};
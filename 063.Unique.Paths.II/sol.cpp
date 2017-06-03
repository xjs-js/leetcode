// 2017-6-3

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // init
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        // malloc new space
        vector<int> relt(col, 0);

        // walk through the grid
        // update the relt
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (obstacleGrid[i][j] == 1) relt[j] = 0;
                else if (i == 0 && j == 0) relt[j] = 1;
                else if (i == 0) relt[j] = relt[j - 1];
                else if (j == 0) relt[j] = relt[j];
                else relt[j] = relt[j-1] + relt[j];
            }
        }

        // return answer
        return relt[col-1];
    }
};

int main()
{
    vector<vector<int>> nums;
    nums.push_back({0});
    cout << Solution::uniquePathsWithObstacles(nums) << endl;
}
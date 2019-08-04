//  Created by js on 2019/8/4.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int beforeSum = 0;               // 原来grid里所有数的总和
        int row      = grid.size();     // 行的个数
        int col      = grid[0].size();  // 列的个数
        vector<int> topBottom;
        vector<int> leftRight;
        
        // 行
        for (int i = 0; i < row; ++i) {
            int maxHeight = 0;
            // 列
            for (int j = 0; j < col; ++j) {
                int height = grid[i][j];
                maxHeight = max(maxHeight, height);
                beforeSum += height;
            }
            leftRight.push_back(maxHeight);
        }
        
        // 列
        for (int j = 0; j < col; ++j) {
            int maxHeight = 0;
            // 行
            for (int i = 0; i < row; ++i) {
                int Height = grid[i][j];
                maxHeight = max(maxHeight, Height);
            }
            topBottom.push_back(maxHeight);
        }
        
        int afterSum = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                afterSum += min(leftRight[i], topBottom[j]);
            }
        }
        
        return (afterSum - beforeSum);
    }
    
    

};



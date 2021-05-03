class Solution {
public:
    int count(vector<vector<int>>& img1, vector<vector<int>>& img2, int row, int col) {
        int n = img1.size();
        int relt = 0;
        // 向右移动
        for (int i = row; i < n; ++i) {
            for (int j = col; j < n; ++j) {
                if (img1[i][j] == img2[i-row][j-col] && img1[i][j] == 1) {
                    ++relt;
                }
            }
        }
        
        int relt_2 = 0;
        if (row != 0 && col != 0) {
            int newCol = n-1-col;
            for (int i = row; i < n; ++i) {
                for (int j = newCol; j >= 0; --j) {
                    if (img1[i][j] == img2[i-row][n-1-newCol+j] && img1[i][j] == 1) {
                        ++relt_2;
                    }
                }
            }
        }
        
        return max(relt, relt_2);
    }
    
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        int relt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int count_1 = count(img1, img2, i, j);
                int count_2 = count(img2, img1, i, j);
                relt = max(relt, max(count_1, count_2));
            }
        }
        return relt;
    }
};

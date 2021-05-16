class Solution {
public:
    // 每一行先向右移动，然后再旋转
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(); // row
        int n = box[0].size(); // col;
        
        for (int i = 0; i < m; ++i) {
            int numOfStones = 0;
            int prev = -1;
            for (int j = 0; j < n; ++j) {
                char c = box[i][j];
                if (c == '.') {
                    continue;
                } else if (c == '#') {
                    ++numOfStones;
                } else if (c == '*') {
                    int k = j - 1;
                    while (numOfStones--) {
                        box[i][k] = '#';
                        --k;
                    }
                    while (k > prev) {
                        box[i][k] = '.';
                        --k;
                    }
                    prev = j;
                    numOfStones = 0;
                }
            }
            if (numOfStones > 0) {
                int k = n - 1;
                while (numOfStones--) {
                    box[i][k] = '#';
                    --k;
                }
                while (k > prev) {
                    box[i][k] = '.';
                    --k;
                }
            }
        }
        
        vector<vector<char>> relt(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                relt[i][j] = box[m-1-j][i];
            }
        }
        return relt;
    }
};

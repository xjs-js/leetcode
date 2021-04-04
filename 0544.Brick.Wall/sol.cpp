/**
 * @date: 2021-04-04 21:27
 * @note: 写完这题就看比赛 FURIA VS G2
 */

 class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size();   // 墙的高度

        int maxHeight = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < height; ++i) {
            vector<int>& row = wall[i];
            int curIndex = 0;
            int col = row.size();

            for (int j = 0; j < col-1; ++j) {
                curIndex += row[j];
                count[curIndex] += 1;
                maxHeight = max(maxHeight, count[curIndex]);
            }
        }

        return height - maxHeight;
    }
};

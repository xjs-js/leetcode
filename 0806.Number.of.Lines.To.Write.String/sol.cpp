/**
 * @date: 2021-04-12 15:24 Mon
 * @name: 写字符串需要的行数
 */


class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int row = 1;
        int col = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int width = widths[s[i]-'a'];
            if (col + width > 100) {
                ++row;
                col = width;
            } else if (col + width == 100) {
                col = 0;
                ++row;
            } else {
                col += width;
            }
        }
        
        if (col == 0 && s.size() != 0) {
            return {--row, 100};
        }
        
        return {row, col};
    }
};
/* https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/ */

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; ++i) {
            bool isFind = false;
            for (int j = 0; j < ranges.size(); ++j) {
                int start = ranges[j][0];
                int end = ranges[j][1];
                
                if (start <= i && i <= end) {
                    isFind = true;
                    break;
                }
            }
            
            if (!isFind) {
                return false;
            }
            
        }
        return true;
    }
};

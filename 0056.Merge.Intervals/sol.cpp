/**
 * @date: 2021-04-18 23:22
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.emplace_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = result[result.size()-1];
            
            vector<int>& cur = intervals[i];
            
            if (cur[0] > last[1]) {
                result.emplace_back(cur);
            } else {
                last[1] = max(last[1], cur[1]);
            }
        }
        
        return result;
    }
};
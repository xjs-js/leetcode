/**
 * @date: 2021-04-09 21:28 Fri
 * @name: 逃脱阻碍者
 * @url: https://leetcode-cn.com/problems/escape-the-ghosts/
 */

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int delta = abs(target[0]) + abs(target[1]);

        for (size_t i = 0; i < ghosts.size(); ++i) {
            const vector<int>& ghost = ghosts[i];

            int dist = abs(target[0] - ghost[0]) + abs(target[1] - ghost[1]);
            if (dist <= delta) {
                return false;
            }
        }

        return true;
    }
};
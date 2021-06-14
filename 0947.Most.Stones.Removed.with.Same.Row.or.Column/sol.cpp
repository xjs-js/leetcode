class Solution {
public:
    // 好像颜色 c 没什么用
    void dfs(map<int, vector<int>>& x, map<int, vector<int>>& y, int i_x, int i_y, set<pair<int,int>>& isVisited/*, int c */) {
        isVisited.insert({i_x, i_y});

        // handle for row
        vector<int>& row = x[i_x];
        for (int new_y : row) {
            if (!isVisited.count({i_x, new_y})) {
                dfs(x, y, i_x, new_y, isVisited);
            }
        }

        // handle for col
        vector<int>& col = y[i_y];
        for (int new_x : col) {
            if (!isVisited.count({new_x, i_y})) {
                dfs(x, y, new_x, i_y, isVisited);
            }
        }
    }

    // 相当于图的dfs染色
    int removeStones(vector<vector<int>>& stones) {
        map<int, vector<int>> x;
        map<int, vector<int>> y;
        for (int i = 0; i < stones.size(); ++i) {
            int i_x = stones[i][0];
            int i_y = stones[i][1];

            x[i_x].push_back(i_y);
            y[i_y].push_back(i_x);
        }

        int c = 0;
        set<pair<int, int>> isVisited;  // 存放访问过的点

        for (int i = 0; i < stones.size(); ++i) {
            int i_x = stones[i][0];
            int i_y = stones[i][1];

            if (!isVisited.count({i_x, i_y})) {
                dfs(x, y, i_x, i_y, isVisited);
                ++c;
            }
        }
        return stones.size() - c;
    }
};

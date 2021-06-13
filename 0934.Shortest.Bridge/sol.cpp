int x[4] = {-1, 0, +1, 0};
int y[4] = {0, +1, 0, -1};

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& isVisited, int i, int j, int c) {
        isVisited[i][j] = true;
        grid[i][j] = c;

        int n = grid.size();

        for (int k = 0; k < 4; ++k) {
            int dx = i + x[k];
            int dy = j + y[k];

            if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                if (grid[dx][dy] != 0 && !isVisited[dx][dy]) {
                    dfs(grid, isVisited, dx, dy, c);
                }
            }
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        // 先将两个岛屿染色 - 染成1和2
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        queue<pair<int, int>> que;
        int c = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0 && !isVisited[i][j]) {
                    dfs(grid, isVisited, i, j, c);
                    ++c;
                }
                if (grid[i][j] == 1) {
                        que.push({i, j});
                }
            }
        }
        // 将编号为1的岛屿用bfs扩张
        c = 0;
        
        while (!que.empty()) {
            int q = que.size();
            while (q--) {
                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                for (int k = 0; k < 4; ++k) {
                    int dx = i + x[k];
                    int dy = j + y[k];

                    if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                        if (grid[dx][dy] == 0) {
                            grid[dx][dy] = 1;
                            que.push({dx, dy});
                        } else if (grid[dx][dy] == 2){
                            return c;
                        }
                    }
                }
            }
            ++c;
        }

        return 0;
    }
};

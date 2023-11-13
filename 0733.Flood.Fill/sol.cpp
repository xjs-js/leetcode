class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        set<pair<int, int>> isVisited; // 是否添加到queue中
        queue<pair<int, int>> que;
        
        // 添加起点
        que.push({sr, sc});
        isVisited.insert(make_pair(sr, sc));

        int originColor = image[sr][sc];
        int M = image[0].size();
        int N = image.size();
        int idx[4] = {0, 0, -1, +1};
        int idy[4] = {-1, +1, 0, 0};
        
        while (!que.empty()) {
            
            queue<pair<int, int>> inner_que;
            while (!que.empty()) {
                auto& front = que.front();
                inner_que.push(front);
                que.pop();
            }

            while (!inner_que.empty()) {
                auto& front = inner_que.front();
                inner_que.pop();

                int cx = front.first;
                int cy = front.second;

                image[cx][cy] = newColor;

                for (int i = 0; i < 4; ++i) {
                    int nx = cx + idx[i];
                    int ny = cy + idy[i];
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (!isVisited.count({nx, ny}) && image[nx][ny] == originColor) {
                            que.push({nx, ny});
                            isVisited.insert({nx, ny});
                        }
                    }
                } 
            }
        }

        return image;
    }
};

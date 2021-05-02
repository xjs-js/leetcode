class Solution {
public:
    // 拓扑排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 邻接表
        unordered_map<int, vector<int>> adj;
        // 入度
        vector<int> inDegree(numCourses, 0);
        
        // 将 prerequisites 转换成邻接表
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            vector<int>& edge = prerequisites[i];
            int src = edge[1], dst = edge[0];
            
            adj[src].push_back(dst);
            ++inDegree[dst];
        }
        
        int count = 0;
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                que.push(i);
            }
        }
        
        while (!que.empty()) {
            ++count;
            int front = que.front();
            que.pop();
            
            vector<int>& nei = adj[front];
            for (int i : nei) {
                --inDegree[i];
                if (inDegree[i] == 0) {
                    que.push(i);
                }
            }
        }
        
        return count == numCourses;
    }
};

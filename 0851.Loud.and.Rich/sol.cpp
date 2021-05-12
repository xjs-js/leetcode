class Solution {
public:
    // 图，拓扑排序
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        // 出度
        vector<int> out(n, 0);
        // 前驱节点
        unordered_map<int, vector<int>> prev;
        // 计算邻接表和出度
        for (int i = 0; i < richer.size(); ++i) {
            vector<int>& p = richer[i];
            int rich = p[0];
            int poor = p[1];
            ++out[poor];
            prev[rich].push_back(poor);
        }
        
        queue<int> que;
        vector<int> relt(n, 0);
        for (int i = 0; i < n; ++i) {
            if (out[i] == 0) {
                que.push(i);
            }
            relt[i] = i;
        }
        
        while (!que.empty()) {
            int poor = que.front();
            que.pop();
            
            // 更新前一个节点的出度和答案
            vector<int>& before = prev[poor];
            for (int i = 0; i < before.size(); ++i) {
                int b = before[i];
                
                int curLoud = quiet[relt[poor]];
                int prevLoud = quiet[relt[b]];
                if (curLoud < prevLoud) {
                    relt[b] = relt[poor];
                }
                
                --out[b];
                if (!out[b]) {
                    que.push(b);
                }
            }
            
        }
        
        return relt;
    }
};

/**
 * @date: 2021-04-12 20:46 Mon.
 * @cat: 拓扑排序
 */

class Solution {
public:
    unordered_map<int, unordered_set<int>> _unValid;

    /**
     *  判断边<i,j>是否无效，无效返回true，有效返回false
     */
    bool isUnValid(int i, int j) {
        if (_unValid.find(i) == _unValid.end()) {
            return false;
        } else {
            return _unValid[i].count(j);
        }
    }

    /** 设边 <i,j> 为无效 */
    void setUnValid(int i, int j) {
        _unValid[i].insert(j);
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();

        // 将出度为0的顶点加入到result集合中
        unordered_set<int> result;
        for (int i = 0; i < N; ++i) {
            vector<int>& adj = graph[i];
            if (adj.size() == 0) {  // 出度为0
                result.insert(i);
            }
        }

        // 直接返回
        if (result.size() == 0) {
            return {};
        }

        int before = 0;
        do {
            // 记录进入循环前result的大小，如果result没变则出循环
            before = result.size();
            for (int i = 0; i < N; ++i) {
                // 顶点i已经在集合中，直接跳过
                if (result.count(i)) {
                    continue;
                }

                // 访问顶点i的邻接表，找出无效的边并计算 i 的出度
                int cnt = 0;
                vector<int>& adj = graph[i];
                for (int j = 0; j < adj.size(); ++j) {
                    int nei = adj[j];
                    bool isValid = !isUnValid(i,nei);
                    // 边 <i, nei> 有效， 且nei是最终点，将边设为unvalid
                    if (result.count(nei) && isValid) {
                        setUnValid(i, nei);
                        isValid = false;
                    }
                    // 最终边 <i, nei> 是否有效
                    if (isValid) {
                        ++cnt;
                    }
                }
                if (cnt == 0) {
                    result.insert(i);
                }
            }

        } while (result.size() != before);
        
        vector<int> realResult(result.begin(), result.end());
        sort(realResult.begin(), realResult.end());
        return realResult;
    }
};
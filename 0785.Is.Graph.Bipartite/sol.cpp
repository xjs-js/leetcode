/**
 * @name: 判断二分图
 * @url:  https://leetcode-cn.com/problems/is-graph-bipartite/
 * @date: 2021-04-06 23:33
 */

#include "../headers.h"

class Solution {
private:
    unordered_set<int> _setA;
    unordered_set<int> _setB;

public:
    // 访问顶点 i 的邻接表
    void dfs(vector<vector<int>>& graph, int i, vector<bool>& isVisited, bool& isExist) {
        if (isExist) {
            return;
        }

        // 标志顶点 i 的邻接表已经被访问过
        isVisited[i] = true;

        const vector<int>& adj = graph[i];
        for (int j = 0; j < adj.size(); ++j) {
            if (isExist) {
                return;
            }

            int other = adj[j];
            // 判断是否在同一个集合中
            if (_setA.count(other) && _setA.count(i)) {
                isExist = true;
                return;
            } else if (_setB.count(other) && _setB.count(i)) {
                isExist = true;
                return;
            } else {
                // other 没有被归类过
                if (!_setA.count(other) && !_setB.count(other)) {
                    // 寻找合适的集合
                    if (_setA.count(i)) {
                        _setB.insert(other); 
                    } else {
                        _setA.insert(other);
                    }

                    // 对 other 进行 dfs
                    if (!isVisited[other]) {
                        dfs(graph, other, isVisited, isExist);
                    }
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> isVisited(graph.size());

        bool isExist = false; // 是否存在矛盾
        for (int i = 0; i < graph.size(); ++i) {
            if (isExist) {
                return false;
            }

            // i 的 邻接表已经访问过
            if (isVisited[i]) {
                continue;
            }

            const vector<int>& adj = graph[i];
            // 顶点 i 是个独立的连通分量
            if (adj.size() == 0) {
                continue;
            } else {
                // 相当于一次 dfs 
                _setA.insert(i);
                for (int j = 0; j < adj.size(); ++j) {
                    int other = adj[j];
                    _setB.insert(other);
                }
                isVisited[i] = true;
                for (int j = 0; j < adj.size(); ++j) {
                    if (isExist) {
                        return false;
                    }
                    int other = adj[j];
                    if (!isVisited[other]) {
                        dfs(graph, other, isVisited, isExist);
                    }
                }
            }
        }

        return !isExist;
    }
};


int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> graph{{1,3},{0,2}, {1,3}, {0,2}};
    cout << boolalpha << sol.isBipartite(graph) << endl;
    return 0;
}

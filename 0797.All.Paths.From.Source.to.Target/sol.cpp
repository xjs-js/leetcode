/**
 * @date: 2021-04-07 22:08
 * @note: 这是一道图的题目，不一定做的出来
 */

#include "../headers.h"

class Solution {
private:
    vector<vector<int>> _result;
public:
    void dfs(vector<vector<int>>& graph, int curNode, vector<int> nodes) {
        vector<int>& neighbors = graph[curNode];
        int N = graph.size();
        for (int i = 0; i < neighbors.size(); ++i) {
            int nextNode = neighbors[i];
            nodes.push_back(nextNode);

            if (nextNode == N - 1) {
                _result.emplace_back(nodes);
            } else {
                dfs(graph, nextNode, nodes);
            }
            nodes.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, {0});
        return _result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> graph{{1,2}, {3}, {3}, {}};
    Solution* sol = new Solution;
    auto result = sol->allPathsSourceTarget(graph);
    Print2DArray(result);
    return 0;
}
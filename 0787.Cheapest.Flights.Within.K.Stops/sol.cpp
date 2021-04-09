/**
 * @date: 2021-04-09 15:57
 * @name: K 站中转内最便宜的航班
 * @url: https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
 */

#include "../headers.h"

class Solution {
private:
    int _result;

private:
    /**
     *
     * @param adj       邻接表
     * @param src       新的源点
     * @param dst       目的地
     * @param K         新的K
     * @param cost      累计的钱
     */
    void dfs(unordered_map<int, vector<pair<int, int>>>& adj, int src, int dst, int K, int cost) {
        // 找到了目的地
        if (src == dst) {
            // 将 cost 更新到 _result
            if (_result == -1) {
                _result = cost;
            } else {
                _result = min(_result, cost);
            }
        } else {
            // 不能再往下走
            if (K == -1) {
                return;
            } else {
                // 从邻接表中取
                auto neighbors = adj[src];
                for (size_t i = 0; i < neighbors.size(); ++i) {
                    const pair<int, int>& info = neighbors[i];
                    
                    // 费用判断，// 剪枝
                    if (_result != -1 && info.second + cost > _result) {
                        continue;
                    } else {
                        dfs(adj, info.first, dst, K-1, cost + info.second);
                    }
                }
            }
        }


    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // 将 flights 转换成邻接表
        unordered_map<int, vector<pair<int, int>>> adj;
        for (size_t i = 0; i < flights.size(); ++i) {
            const vector<int>& tup = flights[i];
            // 源城市、目的地城市、机票价格
            int s = tup[0], d = tup[1], cost = tup[2];
            adj[s].emplace_back(make_pair(d, cost));
        }

        // 初始化最终结果
        _result = -1;

        const vector<pair<int, int>>& neighbors = adj[src];
        for (size_t i = 0; i < neighbors.size(); ++i) {
            // 邻居 和 航班价格
            const pair<int, int>& info = neighbors[i];

            // 剪枝
            if (_result != -1 && info.second > _result) {
                continue;
            } else {
                dfs(adj, info.first, dst, K-1, info.second);
            }
        }

        return _result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<vector<int>> flights{{0,1,100},{1,2,100},{0,2,500}};
    cout << sol.findCheapestPrice(3, flights, 0, 2, 1) << endl;
    return 0;
}
class Solution {
private:
    vector<int> _isPrime;
    vector<bool> _isVisited;
    vector<vector<int>> _adj;
    set<pair<int, int>> _reltSet;
    int _relt;
private:
    // 素数筛
    void buildPrimes(int n) {
        _isPrime.resize(n + 1, true);
        _isPrime[0] = _isPrime[1] = false;
        for (int i = 2; i <= n; ++i) {
            if (_isPrime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    _isPrime[j] = false;
                }
            }
        }
    }

    void dfs(int root, int node, int numOfPrimes) {
        if (_isVisited[node]) return ;

        _isVisited[node] = true;
        if (numOfPrimes == 0) {
            if (_isPrime[node]) {
                numOfPrimes += 1;
                if (root != node)
                    _reltSet.insert({min(root, node), max(root, node)});
            }
            vector<int>& neighbours = _adj[node];
            for (int nei : neighbours) {
                dfs(root, nei, numOfPrimes);
            }
        } else if (numOfPrimes == 1) {
            if (_isPrime[node]) {
                numOfPrimes += 1;
                // terminate
            } else {
                if (root != node)
                    _reltSet.insert({min(root, node), max(root, node)});
                vector<int>& neighbours = _adj[node];
                for (int nei : neighbours) {
                    dfs(root, nei, numOfPrimes);
                }
            }
        }
    }

public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        buildPrimes(n);

        _adj.resize(n+1, vector<int>());

        for (auto& edge : edges) {
            int lhs = edge[0];
            int rhs = edge[1];

            _adj[lhs].push_back(rhs);
            _adj[rhs].push_back(lhs);
        }

        _isVisited.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) _isVisited[j] = false;
            dfs(i, i, 0);
        }

        auto it = _reltSet.begin();
        while (it != _reltSet.end()) {
            cout << it->first << ", " << it->second << endl;
            ++it;
        }
        return _reltSet.size();
    }
};
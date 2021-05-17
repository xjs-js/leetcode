class Solution {
public:
    vector<int> _isVisit;   // 存放第几个集合
    map<int, set<int>> _adj;
    set<int> _set1;
    set<int> _set2;
    bool _relt;
    
    // 对节点 k 进行dfs
    void visit(int k) {
        if (!_relt) {
            return ;
        } else {
            // 节点 k 当前所在的集合
            // 0: 没有被放置; 1: _set1; 2: _set2
            int num = _isVisit[k];
            
            set<int>& s = _adj[k];
            // 没有被放置
            if (num == 0) {
                // 遍历所有的邻居，可以检查是否有冲突，并确定节点k对应的num值    
                for (auto it = s.begin(); it != s.end(); ++it) {
                    int j = *it;
                    if (!_set1.count(j) && !_set2.count(j)) {
                        continue;
                    } else if (_set1.count(j) && _set2.count(j)) {
                        _relt = false;
                        return ;
                    } else if (_set1.count(j)) {
                        if (num == 0) {
                            num = 2;
                        } else if (num == 1) {
                            _relt = false;
                            return ;
                        }
                    } else if (_set2.count(j)) {
                        if (num == 0) {
                            num = 1;
                        } else if (num == 2) {
                            _relt = false;
                            return ;
                        }
                    }
                }

                // 根据num确定插入的集合
                if (num == 1 || num == 0) {
                    _set1.insert(k);
                    _isVisit[k] = 1;
                    num = 1;
                } else {
                    _set2.insert(k);
                    _isVisit[k] = 2;
                }
            }
            
            
            // 遍历所有没访问过的邻居，确定它们的集合，然后访问一遍
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (!_isVisit[*it]) {
                    _isVisit[*it] = (num == 1) ? 2 : 1;
                    visit(*it);
                } else {
                    if (_isVisit[*it] == num) {
                        _relt = false;
                        return ;
                    }
                }
            }
        }
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        _isVisit.resize(n+1, 0);
        _relt = true; 
        
        // 构建无向图的邻接表
        for (int i = 0; i < dislikes.size(); ++i) {
            vector<int>& v = dislikes[i];
            
            _adj[v[0]].insert(v[1]);
            _adj[v[1]].insert(v[0]);
        }
        
        // 遍历邻接表
        auto it = _adj.begin();
        while (it != _adj.end()) {
            if (!_relt) {
                return false;
            }
            
            // 没有访问过，就去访问
            if (!_isVisit[it->first]) {
                visit(it->first);
            }
            
            ++it;
        }
        
        return true;
    }
};

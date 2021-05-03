class Solution {
public:
    map<pair<int, int>, bool> _memo;
    
    bool isReachable(unordered_map<int,vector<int>>& adj, int src, int dst) {
        if (_memo.find({src, dst}) != _memo.end()) {
            return _memo[{src, dst}];
        }
        
        vector<int>& neis = adj[src];
        bool relt = false;
        for (int i = 0; i < neis.size(); ++i) {
            int ne = neis[i];
            
            if (ne == dst) {
                relt = true;
                _memo[{src, dst}] = true;
                return true;
            } else {
                relt = isReachable(adj, ne, dst);
                if (relt) {
                    _memo[{src, dst}] = true;
                    return true;
                }
            }
        }
        
        _memo[{src, dst}] = false;
        return false;
    }
    
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 邻接表
        unordered_map<int, vector<int>> adj;
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            vector<int>& p = prerequisites[i];
            int src = p[0], dst = p[1];
            
            adj[src].push_back(dst);
        }
        
        vector<bool> relt(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            vector<int>& curQuery = queries[i];
            relt[i] = isReachable(adj, curQuery[0], curQuery[1]);
        }
        return relt;
    }
};

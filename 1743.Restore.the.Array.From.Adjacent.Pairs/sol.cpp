class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, int> count;
        unordered_map<int, vector<int>> adj;

        for (auto& v : adjacentPairs) {
            int lhs = v[0];
            int rhs = v[1];

            adj[lhs].push_back(rhs);
            adj[rhs].push_back(lhs);

            ++count[lhs];
            ++count[rhs];
        }

        vector<int> relt;

        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second == 1) {
                relt.push_back(it->first);
                break;
            }
        }

        int prev = relt[0];
        unordered_set<int> st;
        st.insert(prev);
        for (int i = 1; i <= adjacentPairs.size(); ++i) {
            auto& v = adj[prev];
            for (auto next : v) {
                if (!st.count(next)) {
                    relt.push_back(next);
                    prev = next;
                    st.insert(next);
                    break;
                }
            }
        }
        return relt;
    }
};

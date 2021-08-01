class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> memo;
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    ++count;
                } else {
                    break;
                }
            }
            memo[i] = count;
        }

        vector<int> arr;
        for (int i = 0; i < m; ++i) arr.push_back(i);

        sort(arr.begin(), arr.end(), [&](int lhs, int rhs) {
            if (memo[lhs] < memo[rhs]) {
                return true;
            } else if (memo[lhs] == memo[rhs]) {
                return lhs < rhs;
            } else {
                return false;
            }
        });

        vector<int> relt;
        for (int i = 0; i < k; ++i) {
            relt.push_back(arr[i]);
        }
        return relt;
    }
};

class Solution {
private:
    vector<int> _relt;

    void dfs(int idx, int k, int n, int last, int cur) {
        if (idx == n) {
            _relt.push_back(cur);
            return;
        } else {
            if (last + k <= 9) {
                dfs(idx + 1, k, n, last + k, cur * 10 + last + k);
            }

            if (k != 0 && last - k >= 0) {
                dfs(idx + 1, k, n, last - k, cur * 10 + last - k);
            }

        }

    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; ++i) {
            dfs(1, k, n, i, i);
        }
        return _relt;
    }
};

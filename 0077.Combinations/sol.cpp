class Solution {
private:
    vector<vector<int>> _relt;
    vector<int> _curRelt;
    
    void dfs(int k, int n, int cur) {
        if (k == 0) {
            _relt.push_back(_curRelt);
            return;
        } else if (cur > n || k < 0) {
            return ;
        } else {
            for (int i = cur; i <= n; ++i) {
                _curRelt.push_back(i);
                dfs(k-1, n, i+1);
                _curRelt.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(k, n, 1);
        return _relt;
    }
};
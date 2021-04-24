class Solution {
private:
    vector<vector<int>> _relt;
    vector<int> _curRelt;
    
    void dfs(int k, int n, int cur) {
        if (k == 0 && n == 0) {
            _relt.push_back(_curRelt);
            return;
        } else if (n < 0 || k < 0 || cur > 9) {
            return ;
        } else {
            for (int i = cur; i <= 9; ++i) {
                if (i + (k-1)*i <= n && i + (k-1)*9 >= n) {
                    _curRelt.push_back(i);
                    dfs(k-1, n-i, i+1);
                    _curRelt.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return _relt;
    }
};
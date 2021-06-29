class Solution {
private:
    unordered_set<int> _relt;
    set<pair<int, int>> _memo;

    void dfs(int x, int y, int bound, int i, int j) {
        int left = (int)pow(x, i);
        int right = (int)pow(y, j);
        if (_memo.count({left, right})) {
            return ;
        } else {
            _memo.insert({left, right});
        }

        int curNum = left + right;
        if (curNum <= bound ) {
            _relt.insert(curNum);
            dfs(x, y, bound, i, j+1);
            dfs(x, y, bound, i+1, j);
        }
    }
public:
    vector<int> powerfulIntegers(int x, int y, int bound) { 
        dfs(x, y, bound, 0, 0);

        vector<int> arr(_relt.begin(), _relt.end());
        return arr;
    }
};

class Solution {
private:
    vector<vector<int>> _relt;
    vector<int> _curRelt;
    
    void dfs(vector<int>& cand, int target, int curIndex) {
        if (target == 0) {
            _relt.emplace_back(_curRelt);
            return;
        } else {
            int prev = -1;
            for (int i = curIndex; i < cand.size(); ++i) {
                int curNum = cand[i];
                if (curNum > target) {
                    return;
                } else if (curNum == prev) {
                    continue;
                } else {
                    prev = curNum;
                    _curRelt.emplace_back(curNum);
                    dfs(cand, target - curNum, i+1);
                    _curRelt.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        dfs(cand, target, 0);
        return _relt;
    }
};
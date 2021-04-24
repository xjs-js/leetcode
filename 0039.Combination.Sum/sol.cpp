class Solution {
private:
    vector<vector<int>> _result;
    
public:
    // 从当前坐标i来计算
    void dfs(vector<int>& cand, int target, int i, vector<int>& curRelt) {
        if (target == 0) {
            _result.emplace_back(curRelt);
        } else {
            for (int j = i; j < cand.size(); ++j) {
                int curC = cand[j];
                if (curC > target) {
                    return;
                } else {
                    curRelt.push_back(curC);
                    dfs(cand, target-curC, j, curRelt);
                    curRelt.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<int> curRelt;
        dfs(cand, target, 0, curRelt);
        return _result;
    }
};

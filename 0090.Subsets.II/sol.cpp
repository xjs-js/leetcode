/**
 * @date: 2021-03-31
 */

class Solution {
private:
    set<vector<int>> _result;
    vector<int> _subSet;
private:
    void search(vector<int>& nums, int i) {
        if (i == nums.size()) {
            _result.insert(_subSet);
            return;
        }

        _subSet.push_back(nums[i]);
        search(nums, i+1);
        _subSet.pop_back();
        search(nums, i+1);
    }

public:
    /**
     * 我直接用了set来去除重复的情况，按理来说，要用回溯法
     */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 先排序
        sort(nums.begin(), nums.end());
        // 找子集
        search(nums, 0);

        return vector<vector<int>> {_result.begin(), _result.end()};
    }
};
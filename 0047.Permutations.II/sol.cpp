class Solution {
public:
    vector<bool> _choose;
    vector<int> _cur;
    vector<vector<int>> _relt;

    void search(vector<int>& nums) {
        if (_cur.size() == nums.size()) {
            _relt.emplace_back(_cur);
        } else {
            bool isFirst = true;
            // 当前位置的最后一个值
            int last = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (_choose[i])  continue;

                if (isFirst) {
                    last = nums[i];
                    isFirst = false;
                } else {
                    // 现在的值和上次搜索的最后一个值相等
                    if (nums[i] == last) {
                        continue;
                    }
                }

                last = nums[i];
                _choose[i] = true;
                _cur.push_back(nums[i]);
                search(nums);
                _cur.pop_back();
                _choose[i] = false;

            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        _choose.resize(n, false);

        search(nums);

        return _relt;
    }
};

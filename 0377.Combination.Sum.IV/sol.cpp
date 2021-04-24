class Solution {
private:
    unordered_map<int, int> _memo;
    bool _first;
    
public:
    Solution() : _first(false) {}
    
    int combinationSum4(vector<int>& nums, int target) {
        if (!_first) {
            sort(nums.begin(), nums.end());
            _first = true;
        }
        
        if (_memo.find(target) != _memo.end()) {
            return _memo[target];
        }
        
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            if (cur > target) {
                break;
            } else if (cur == target) {
                ++result;
            } else {
                result += combinationSum4(nums, target - cur);
            }
        }
        
        _memo[target] = result;
        return result;
    }
};
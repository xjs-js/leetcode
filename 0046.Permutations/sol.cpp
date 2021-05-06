class Solution {
public:
    vector<bool> _choose;
    vector<int> _cur;
    vector<vector<int>> _relt;
    
    void search(vector<int>& nums) {
        if (_cur.size() == nums.size()) {
            _relt.emplace_back(_cur);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (_choose[i])  continue;
                
                _choose[i] = true;
                _cur.push_back(nums[i]);
                search(nums);
                _cur.pop_back();
                _choose[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        _choose.resize(n, false);
        
        search(nums);
        
        return _relt;
    }
};

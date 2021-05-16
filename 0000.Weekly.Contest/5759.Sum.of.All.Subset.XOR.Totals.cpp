class Solution {
public:
    
    vector<int> _curRelt;
    int _sum;
    void search(vector<int>& nums, int k) {
        if (k == nums.size()) {
            if (_curRelt.size() == 0) {
                _sum += 0;
            } else {
                int x = _curRelt[0];
                for (int i = 1; i < _curRelt.size(); ++i) {
                    x ^= _curRelt[i];
                }
                _sum += x;
            }
        } else {
            _curRelt.push_back(nums[k]);
            search(nums, k+1);
            _curRelt.pop_back();
            search(nums, k+1);
        }
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        _sum = 0;
        
        search(nums, 0);
        return _sum;
    }
};

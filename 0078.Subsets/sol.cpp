class Solution {
public:
    vector<vector<int>> _relt;
    vector<int> _path;
    
    void search(vector<int>& nums, int curInd) {
        int n = nums.size();
        
        if (curInd == n) {
            _relt.emplace_back(_path);
            return ;
        } 
        
        search(nums, curInd + 1);
        _path.push_back(nums[curInd]);
        search(nums, curInd + 1);
        _path.pop_back();

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        search(nums, 0);
        return _relt;
    }
};
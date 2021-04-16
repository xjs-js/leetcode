/**
 * @date: 2021-04-16 21:29 Fry.
 */

class Solution {
    vector<int> _nums;
    vector<int> _result;
public:
    Solution(vector<int>& nums) {
        _nums = nums;
        _result = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        _result = _nums;
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int N = _nums.size();
        
      
        for (int i = _result.size()-1; i >= 1; --i) {
          swap(_result[rand() % (i+1)], _result[i]);
        }
        return _result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
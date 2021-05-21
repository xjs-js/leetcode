class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int relt = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            relt ^= nums[i];
        }
        if (relt == 0) {
            return true;
        }
        
        
        int n = nums.size();
        if (n % 2 == 1) {
            return false;
        } else {
            return true;
        }
    }
};

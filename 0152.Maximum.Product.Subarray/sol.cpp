class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prevMin(nums.size());
        vector<int> prevMax(nums.size());
        
        prevMin[0] = prevMax[0] = nums[0];
        int maxMult = prevMax[0];
        for (int i = 1; i < nums.size(); ++i) {
            int curNum = nums[i];
            int num_1 = prevMin[i-1] * curNum;
            int num_2 = prevMax[i-1] * curNum;
            
            prevMin[i] = min({curNum, num_1, num_2});
            prevMax[i] = max({curNum, num_1, num_2});
            maxMult = max(maxMult, prevMax[i]);
        }
        return maxMult;
    }
};
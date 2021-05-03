class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> relt(n, 0);
        
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            relt[i] = totalSum;
        }
        
        return relt;
    }
};

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> prev;
        
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
        }
        
        int maxDp = dp[0];
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int rhs = nums[i];
            int maxPrev = 0;
            int prevNum = 0;
            for (int j = i-1; j >= 0; --j) {
                int lhs = nums[j];
                if (rhs % lhs == 0) {
                   if (dp[j] > maxPrev) {
                       maxPrev = dp[j];
                       prevNum = nums[j];
                   }
                }
            }
            if (maxPrev > 0) {
                prev[rhs] = prevNum;
                dp[i] = maxPrev + 1;
            }
            if (dp[i] > maxDp) {
                maxDp = dp[i];
                maxNum = nums[i];
            }
        }
        
        
        vector<int> result({maxNum});
        int cur = maxNum;
        while (prev[cur] != 0) {
            result.push_back(prev[cur]);
            cur = prev[cur];
        }
    
        return result;
    }
};
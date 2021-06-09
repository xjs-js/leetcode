class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        int dp[n];
        memset(dp, 0, sizeof dp);
        
        dp[0] = nums[0];
        priority_queue<int> pq;
        unordered_map<int, int> count;
        
        pq.push(dp[0]);
        for (int i = 1; i < n; ++i) {
            int top = pq.top();
            while (count[top]) {
                --count[top];
                pq.pop();
                top = pq.top();
            }
            
            
            dp[i] = pq.top() + nums[i];
            
            if (i - k >= 0) {
                // delete dp[i-k];
                if (dp[i-k] == pq.top()) {
                    pq.pop();
                } else {
                    ++count[dp[i-k]];
                }
            }
            
            pq.push(dp[i]);
        }
        
        return dp[n-1];
    }
};

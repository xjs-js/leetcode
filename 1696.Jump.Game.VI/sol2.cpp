class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        // dp[i] 表是从i开始跳到最后的最小值
        vector<int> dp(n, -1);
        
        // 用最大堆维护k个元素的最大值
        priority_queue<int> pq;
        dp[n-1] = nums[n-1];
        pq.push(dp[n-1]);
        
        // 还没有删除的个数
        unordered_map<int, int> count;
        for (int i = n-2; i >= 0; --i) {
            // 后 k 个元素的最大值
            int top = pq.top();
            while (count[top] > 0) {
                --count[top];
                pq.pop();
                top = pq.top();
            }
            
            dp[i] = nums[i] + pq.top();
            
            if (pq.size() >= k) {
                if (dp[i+k] == top) {
                    pq.pop();     
                } else {
                    ++count[dp[i+k]];
                }
            }
            
            pq.push(dp[i]);
        }
        
        return dp[0];
    }
};

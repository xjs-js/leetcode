class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] 表示 第i个格子能否跳到最后
        vector<bool> dp(n, false);
        vector<int> dist(n, -1);
        
        // 最后一个格子
        dp[n-1] = true;
        dist[n-1] = 0;
        for (int i = n-2; i >= 0; --i) {
            int curStep = nums[i];
            
            for (int j = 1; j <= curStep && i+j <= n - 1; ++j) {
                if (dp[i+j]) {
                    dp[i] = true;
                    dist[i] = dist[i] == -1 ? 1 + dist[i+j] : min(dist[i], 1 + dist[i+j]);
                }
            }
            // cout << "i: " << i << " dist[i]: " << dist[i] << endl;
        }
        
        return dist[0];
    }
};

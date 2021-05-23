class Solution {
public:
    bool calc(vector<int>& sum, int i, int minJump, int maxJump) {
        int l = i - maxJump;
        int r = i - minJump;
        
        if (r < 0) {
            return false;
        } else {
            if (l <= 0) {
                return sum[r];
            } else {
                return (sum[r] - sum[l-1]);
            }
        }
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n-1] != '0') {
            return false;
        }
        
        vector<bool> dp(n, false);
        vector<int> sum(n, 0);
        dp[0] = true;
        sum[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                dp[i] = false;
            } else {
                dp[i] = calc(sum, i, minJump, maxJump);
            }
            
            sum[i] = sum[i-1] + (dp[i] ? 1 : 0);
        }
        
        return dp[n-1];
    }
};

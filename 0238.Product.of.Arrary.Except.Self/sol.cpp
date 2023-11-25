// 2023.11.21 20:38
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();

        vector<int> relt(N, 1);
        vector<int> prev(N, 1);
        vector<int> next(N, 1);
        
        prev[0] = nums[0];
        for (int i = 1; i < N; ++i)
            prev[i] = nums[i] * prev[i-1];

        next[N-1] = nums[N-1];
        for (int i = N-2; i >=0; --i)
            next[i] = nums[i] * next[i+1];
        
        for (int i = 0; i < N; ++i) {
            if (i == 0) relt[i] = next[i + 1];
            else if (i == N-1) relt[i] = prev[i - 1];
            else {
                relt[i] = prev[i - 1] * next[i + 1];
            }
        }

        return relt;
    }
};

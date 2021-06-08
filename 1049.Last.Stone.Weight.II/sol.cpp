class Solution {
public:
    int pkg(vector<int>& vol, vector<int>& val, int v) {
        int f[v+1];
        memset(f, 0, sizeof f);
        int n = val.size();
        for (int i = 0; i < n; ++i) {
            int curVol = vol[i];
            int curVal = val[i];
            
            for (int j = v; j >= curVol; --j) 
                f[j] = max(f[j], f[j - curVol] + curVal);
        }
        
        return f[v];
    }

    int calc(vector<int>& nums, int target) {
        return pkg(nums, nums, target);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); ++i) sum += stones[i];
        int relt = calc(stones, sum/2);

        return (sum - relt) - relt;
    }
};

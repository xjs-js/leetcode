class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = 10001, maxNum = -1;
        for (int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        
        int delta = maxNum - k - minNum - k;
        return delta >= 0 ? delta : 0;
    }
};

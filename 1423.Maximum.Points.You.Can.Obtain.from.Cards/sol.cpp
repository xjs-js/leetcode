class Solution {
public:
    // 滑动窗口
    int maxScore(vector<int>& cardPoints, int k) {
        // 计算前k个
        int sum = 0;
        int relt = 0;
        for (int i = 0; i < k; ++i)
            sum += cardPoints[i];
        relt = sum;
        
        int n = cardPoints.size();
        if (n == k) {
            return relt;
        }
        
        for (int i = 0; k - 1 - i >= 0; ++i) {
            sum = sum - cardPoints[k-1-i] + cardPoints[n-1-i];
            relt = max(relt, sum);
        }
        
        return relt;
    }
};

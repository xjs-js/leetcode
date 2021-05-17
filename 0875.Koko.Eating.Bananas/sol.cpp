class Solution {
public:
    
    // 给定吃香蕉速度K，返回能否在h小时内吃掉
    bool canMatch(vector<int>& piles, int h, int k) {
        int relt = 0;
        for (int i = 0; i < piles.size(); ++i) {
            if (piles[i] % k == 0) {
                relt += (piles[i] / k);
            } else {
                relt += (piles[i] / k + 1);
            }
        }
        return relt <= h;
    }
    
    // 二分答案
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxP = piles[0];
        for (int i = 1; i < piles.size(); ++i) {
            maxP = max(maxP, piles[i]);
        }
        
        int beg = 1;
        int end = maxP;
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (canMatch(piles, h, mid)) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        
        return end;
    }
};

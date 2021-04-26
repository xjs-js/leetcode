class Solution {
public:
    // 这么多物品能否在D天内运送完成
    bool possible(vector<int>& w, int D, int limit) {
        int j = 0;
        for (int i = 1; i <= D && j < w.size(); ++i) {
            int today = limit;
            while (j < w.size() && today >= w[j]) {
                today -= w[j++];
            }
            if (j == w.size()) {
                return true;
            }
        }
        return j == w.size();
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int totalW = 0;
        for (auto w : weights) totalW += w;
        
        int l = 0, r = totalW;
        int relt = 1e9;
        while (l <= r) {
            int mid = l + r >> 1;
            // cout << mid << endl;
            if (possible(weights, D, mid)) {
                relt = min(relt, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return relt;
    }
};
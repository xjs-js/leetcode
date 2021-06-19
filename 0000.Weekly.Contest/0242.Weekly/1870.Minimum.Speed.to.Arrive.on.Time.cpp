// https://leetcode-cn.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    bool match(vector<int>& dist, int speed, double hour) {
        int n = dist.size();
        double total = 0;
        for (int i = 0; i < n-1; ++i) {
            if (dist[i] % speed == 0) {
                total += (dist[i] / speed);
            } else {
                total += (dist[i] / speed) + 1;
            }
        }
        total += (dist[n-1] * 1.0 / speed);
        // cout << total << endl;
        if (total <= hour) {
            return true;
        } else {
            return false;
        }
    }
    
    // 二分答案
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int maxDist = -1;  // speed 最大，hour 最小
        for (int i = 0; i < n; ++i) {
            maxDist = max(maxDist, dist[i]);
        }
        
        double lastTime = hour - (n - 1);
        
        if (lastTime <= 0) {
            return -1;
        }
        int r = (int) ceil(dist[n-1] / lastTime);
        //cout << r << endl;
        r = max(r, maxDist);
        int l = 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (match(dist, mid, hour)) {
                //cout << "match: " << mid << endl;
                r = mid; 
            } else {
                //cout << "unmatch: " << mid << endl;
                l = mid + 1;
            }
        }
        
        return r;
    }
};
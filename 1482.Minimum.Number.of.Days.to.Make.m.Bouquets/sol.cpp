class Solution {
public:
    // day天是否满足需要
    bool isEnough(vector<int>& bloomDay, int m, int k, int day) {

        int n = bloomDay.size();

        int relt = 0;
        int i = 0;
        while (i < n && i + k - 1 < n) {            
            int count = 0;
            int d = k;
            while (d-- && bloomDay[i++] <= day) {
                ++count;
            }
            
            if (count == k) {
                ++relt;
            }
        }

        return relt >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int minDay = 1e9, maxDay = 1;
        int n = bloomDay.size();

        if (m * k > n) {
            return -1;
        }

        for (int i = 0; i < n; ++i) {
            minDay = min(bloomDay[i], minDay);
            maxDay = max(bloomDay[i], maxDay);
        }

        int beg = minDay;
        int end = maxDay;
        while (beg < end) {
            int mid = (beg + end) / 2;
            if (isEnough(bloomDay, m, k, mid)) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }

        return end;
    }
};

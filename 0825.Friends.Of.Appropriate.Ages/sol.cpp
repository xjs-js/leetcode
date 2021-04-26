class Solution {
public:
    // 二分查找
    int binarySearch(vector<int>& ages, int beg, int end, int ageA) {
        double limit = 0.5 * ageA + 7;

        if ((double)ages[end] <= limit) {
            return 0;
        }
        
        int originEnd = end;
        
        while (beg < end) {
            int mid = (beg + end) / 2;
            if ((double)ages[mid] > limit) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        
        return originEnd + 1 - end;
    }
    
    int numFriendRequests(vector<int>& ages) {
        // 首先排序，这样第二点和第三点限制就完全不存在，只需要考虑第一种
        sort(ages.begin(), ages.end());
        
        int n = ages.size();
        
        // 前一个人有多少朋友
        int prevRelt = 0;
        // 有多少人和前一个人年龄相同
        int prevCount = 1;
        int relt = 0;
        
        for (int i = 1; i < n; ++i) {
            // age[A]
            int A = ages[i];
            // age[A] 和 前一个人相同年龄
            if (A == ages[i-1]) {
                if (A > 14) {
                    // 相同年龄的人之间可以交朋友
                    relt += prevCount * 2;
                }
                // 相同年龄的人加一
                ++prevCount;
                // 加上不同年龄的朋友数
                relt += prevRelt;
            } else {
                // 二分查找
                int curRelt = binarySearch(ages, 0, i-1, A);
                // 更新 prevRelt 和 prevCount
                prevRelt = curRelt;
                prevCount = 1;
                relt += curRelt;
            }
        }
        
        return relt;
    }
};
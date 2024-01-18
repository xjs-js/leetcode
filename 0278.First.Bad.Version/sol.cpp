/**
 * @date: 2021-04-16 17:45 Fry.
 * @cat: 二分搜索
 */

class Solution {
public:
    int _versionNum;
    int firstBadVersion(int n) {
        _versionNum = -1;
        
        int beg = 1;
        int end = n;
        
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            
            if (isBadVersion(mid)) {
                if (_versionNum == -1) {
                    _versionNum = mid;
                } else {
                    if (_versionNum > mid) {
                        _versionNum = mid;
                    }
                }
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        
        return _versionNum;
    }
};

/**
 * @date: 2024-01-18 10:41
 */

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;

        while (l < r) {
            long long mid = (l + r) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
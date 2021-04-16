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
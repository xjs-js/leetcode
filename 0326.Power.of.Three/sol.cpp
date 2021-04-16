/**
 * @date: 2021-04-16 Fri. 20:53
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        
        // 3^0
        if (n == 1) {
            return true;
        }
        
        while (n) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
            if (n == 1) {
                return true;
            }
        }
        
        return true;
    }
};
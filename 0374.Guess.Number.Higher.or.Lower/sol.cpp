/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

typedef long long LL;

class Solution {
public:
    int guessNumber(int n) {
        // 二分
        LL i = 0, j = n;
        while (i <= j) {
            LL mid = (i + j) / 2;

            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) < 0) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return -1;
    }
};

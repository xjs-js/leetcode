/**
 * @date: 2021-04-10 13:16
 * @name: 丑数
 * @url: https://leetcode-cn.com/problems/ugly-number/
 */

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        if (n == 1 || n == 2 || n == 3 || n == 5) {
            return true;
        }

        bool result = false;
        if (n % 2 == 0) {
            result = result || isUgly(n / 2);
        }

        if (n % 3 == 0) {
            result = result || isUgly(n / 3);
        }

        if (n % 5 == 0) {
            result = result || isUgly(n / 5);
        }

        return result;
    }
};
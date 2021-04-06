/**
 * @date: 2021-04-06 21:03
 * @note: 今天最后一题
 */

class Solution {
private:
    // 返回旋转之后的数字
    // digit取值范围为0~9
    // 不能旋转返回-1
    int getRotated(int digit) {
        if (digit == 3 || digit == 4 || digit == 7) {
            return -1;
        }

        if      (digit == 0) return 0;
        else if (digit == 1) return 1;
        else if (digit == 2) return 5;
        else if (digit == 5) return 2;
        else if (digit == 6) return 9;
        else if (digit == 8) return 8;
        else if (digit == 9) return 6;

        return -1;
    }

    // 判断一个数是否是好数
    bool isGoodNum(int num) {
        int isSame = true;
        while (num != 0) {
            int digit = num % 10;
            int rotated = getRotated(digit);
            if (rotated == -1) {
                return false;
            } else if (rotated != digit) {
                isSame = false;
            }
            num /= 10;
        }
        
        return !isSame;
    }

public:
    int rotatedDigits(int N) {
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGoodNum(i)) {
                ++result;
            }
        }
        return result;
    }
};

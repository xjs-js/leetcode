/**
 * @date: 2021-04-16 Fri. 15:43
 */

class Solution {
public:
    int myAtoi(string str) {
        // 读入字符串并丢弃无用的前导空格
        int i = 0;
        while (i < str.size() && str[i] == ' ')
            ++i;
        str = str.substr(i);

        if (str.empty()) {
            return 0;
        }


        bool isNeg = false;
        if (str[0] == '-') {
            isNeg = true;
            str = str.substr(1);
        } else if (str[0] == '+') {
            str = str.substr(1);
        }

        int64_t relt = 0;
        bool hasPre = false;
        for (char c : str) {
            if (!isdigit(c)) {
                if (!hasPre) {
                    return 0;
                } else {
                    break;
                }
            }
            relt = relt * 10 + c - '0';

            if (isNeg) {
                if (relt >= 2147483648)
                    return -2147483648;
            } else {
                if (relt >= 2147483647) {
                    return 2147483647;
                }
            }

            hasPre = true;
        }

        if (isNeg) {
            if (relt >= 2147483648)
                return -2147483648;
            return relt * -1;
        } else {
            if (relt >= 2147483647) {
                return 2147483647;
            }
            return relt;
        }
    }
};
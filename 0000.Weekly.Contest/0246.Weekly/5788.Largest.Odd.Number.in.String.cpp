// https://leetcode-cn.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        for (; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1)  {
                break;
            }
        }
        if (i >= 0) {
            return num.substr(0, i) + num.substr(i, 1);
        } else {
            return "";
        }
    } 
};
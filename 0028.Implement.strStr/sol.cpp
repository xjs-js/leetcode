class Solution {
public:
    int strStr(string haystack, string needle) {
        int leftLen = haystack.size();
        int rightLen = needle.size();

        if (rightLen == 0) {
            return 0;
        }

        if (leftLen < rightLen) {
            return -1;
        }

        if (leftLen == rightLen) {
            if (haystack == needle) {
                return 0;
            } else {
                return -1;
            }
        }

        for (int i = 0; i <= leftLen - rightLen; i++) {
            string subStr = haystack.substr(i, rightLen);
            if (subStr == needle) {
                return i;
            }
        }

        return -1;
    }
};
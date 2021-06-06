class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        // 左边有多少个1，右边有多少个0
        int left[n], right[n];
        memset(left, 0, sizeof left);
        memset(right, 0, sizeof right);

        left[0] = s[0] == '1' ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = left[i-1];
            }
        }

        right[n-1] = s[n-1] == '0' ? 1 : 0;
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = right[i+1];
            }
        }

        int relt = n;
        for (int i = 0; i < n; ++i) {
            /* 左边为0，右边为1 */
            int leftSize = left[i];
            int rightSize = i == n-1 ? 0 : right[i+1];

            relt = min(relt, leftSize + rightSize);

            /* 都为0 */
            leftSize = left[i];
            rightSize = i == n-1 ? 0 : n-1-i-right[i+1];
            relt = min(relt, leftSize + rightSize);

            /* 都为1 */
            leftSize = i + 1 - left[i];
            rightSize = i == n-1 ? 0 : right[i+1];
            relt = min(relt, leftSize + rightSize);
        }
        return relt;
    }
};

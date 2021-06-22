class Solution {
public:
    /* 第k列字母是否有序 */
    bool checkSingle(vector<string>& strs, int k) {
        int n = strs.size();

        for (int i = 1; i < n; ++i) {
            if (strs[i][k] < strs[i-1][k]) {
                return false;
            }
        }
        return true;
    }

    /* k从0开始递增，直到第k列字母有序 */
    /* 找到第k列之后，后面的第[k+1, n)依次累加到第k列，查看是否有序 */ 
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int k = 0;
        /* 从第i开始，strs是否有序 */
        while (k < m) {
            bool isSingle = checkSingle(strs, k);

            if (!isSingle) {
                ++k;
            } else {
                vector<string> cur;
                /* 先保存第k列 */
                for (int i = 0; i < n; ++i) {
                    cur.push_back(strs[i].substr(k, 1));
                }

                /* 依次检查后面的列 */
                for (int j = k + 1; j < m; ++ j) {
                    bool isAll = true;
                    for (int i = 1; i < n; ++i) {
                        if (cur[i]+strs[i].substr(j,1) < cur[i-1] + strs[i-1].substr(j, 1)) {
                            isAll = false;
                            break;
                        }
                    }
                    /* 第j列加入后满足字典序 */
                    if (isAll) {
                        for (int i = 0; i < n; ++i) {
                            cur[i] += strs[i].substr(j, 1);
                        }
                    }
                }
                if (cur.size() > 0) {
                    return m - cur[0].size();
                } else {
                    return 0;
                }
            }
        }
        return m;
    }
};

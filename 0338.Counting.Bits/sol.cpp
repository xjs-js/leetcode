/**
 * @date: 2021-04-01: 21:39
 * @note: 估计这是今天做的最后一题
 */


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;

        result.emplace_back(0);

        for (int i = 1; i <= num; ++i) {
            bitset<32> cur(i);
            result.emplace_back(cur.count());
        }

        return result;
    }
};

/* 就这？太简单了，再做一题 */

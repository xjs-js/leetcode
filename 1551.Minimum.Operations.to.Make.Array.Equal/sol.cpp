/**
 * @date: 2021-04-06 
 * @note: 上一题没做出来，心情失落
 */

class Solution {
public:
    int minOperations(int n) {
        int mid = n / 2;
        int result = 0;
        for (int i = 0; i < mid; ++i) {
            int num = 2 * i + 1;
            result += (n - num);
        }
        return result;
    }
};

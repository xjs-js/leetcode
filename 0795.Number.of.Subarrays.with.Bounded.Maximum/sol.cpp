
/**
 * @date: 2021-04-10 22:10 Sat
 * @name: 区间子数组个数
 * @url: https://leetcode-cn.com/problems/number-of-subarrays-with-bounded-maximum/
 * @note: 动态规划
 */

class Solution {
public:
    /**
     *  从后向前使用动态规划
     *
     *  1. if (A[i] > R)        =>  dp[i] = 0;
     *  2. if (L <= A[i] <= R)  =>  if (A[i+1] >= L)    => dp[i] = 1 + dp[i+1]
     *                          =>  else                => dp[i] = k - i + dp[k], (k is the first index after i, A[k]>= L)              
     *  3. if (A[i] < L)        =>  dp[i] = dp[i+1];
     */     
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int N = A.size();
        vector<int> dp(N);

        // 计算最后一个值
        int i = N-1;
        int cur = A[i];
        if (L <= cur && cur <= R) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }

        // 开始从倒数第二个向前计算
        int result = dp[i];
        for (i = N-2; i >= 0; --i) {
            cur = A[i];
            if (cur > R) {
                dp[i] = 0;
            } else if (L <= cur && cur <= R) {
                if (A[i+1] >= L) {
                    dp[i] = 1 + dp[i+1];
                } else {    // A[i+1] < L
                    int k = i + 1;
                    for (; k < N; ++k) {
                        if (A[k] >= L) {
                            break;
                        }
                    }

                    if (k == N) {
                        dp[i] = k - i;
                    } else {
                        dp[i] = k - i + dp[k];
                    }
                }
            } else {    // cur < L
                dp[i] = dp[i+1];
            }
            result += dp[i];
        }
        return result;
    }
};
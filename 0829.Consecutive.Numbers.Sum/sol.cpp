class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int relt = 0;
        
        for (int k = 1; k * (k - 1) < 2*N; ++k) {
            if (2 * N % k == 0) {
                if ((2*N / k - k + 1) % 2 == 0) {
                    ++relt;
                }
            }
        }
        
        return relt;
    }
};

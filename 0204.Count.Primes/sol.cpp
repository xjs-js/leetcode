/**
 * @date: 2021-04-16 20:20 Fry.
 */

class Solution {
public:
    // 素数筛
    int countPrimes(int n) {
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return 0;
        }
        

        
        int count = 0;
        vector<bool> isPrime(n + 1, true);
        
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = false;
                }
                ++count;
            }
        }
        
        return count;
    }
};
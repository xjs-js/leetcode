class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        
        int prev = -1;
        int i = 0;
        while (n) {
            if (n % 2) {
                if (prev != -1) {
                    maxDist = max(maxDist, i - prev);
                }
                prev = i;
            }
            n /= 2;
            ++i;            
        }
        
        return maxDist;
    }
};

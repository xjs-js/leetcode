class Solution {
public:
    bool judgeSquareSum(int c) {
        int half = sqrt(c);
        
        for (int a = 0; a <= half; ++a) {
            long long b_2 = 1ll * c - a*a;
            long long b = sqrt(b_2);
            if (b * b == b_2) {
                return true;
            }
        }
        return false;
    }
};

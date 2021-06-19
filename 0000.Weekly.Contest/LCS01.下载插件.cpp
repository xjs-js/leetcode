class Solution {
public:
    int leastMinutes(int n) {
        int origin_n = n;
        if (n == 1) {
            return 1;
        } else {
            int i = 0;
            while (n != 1) {
                ++i;
                n /= 2;
            }
            
            if ((int)pow(2, i) == origin_n) {
                return i + 1;
            } else {
                return i + 2;
            }
        }
    }
};


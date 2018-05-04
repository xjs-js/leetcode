class Solution {
public:
   int mySqrt(int x) {
        int64_t k = 0;
        for (int64_t b = x; b >= 1; b /= 2) {
            while ( (k+b)*(k+b) <= x) 
                k += b;   
        }
        return k;
    }

    /* runs faster than the above  */
    int mySqrt(int x) {
        int k = 0;
        for (int b = x; b >= 1; b /= 2) {
            while ( (k+b) <= x / (k+b))
                k += b;
        }
        return k;
    }

    /* Newton-Raphsom method */
    int mySqrt(int x) {
        int64_t y = x;
        while ( y*y > x) {
            y = (y*y+x)/(2*y);  
        }
        return y;
    }

}

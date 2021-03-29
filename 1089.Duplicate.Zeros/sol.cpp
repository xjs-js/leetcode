#include <vector>

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int length = arr.size();
        int i = 0;
        while (i < length) {
            int element = arr[i];
            if (0 == element && i != length-1) {
                // shift right
                for (int j = length - 2; j >= i+1; --j) {
                    arr[j+1] = arr[j];
                }
                arr[i+1] = 0;
                i += 2;
            } else {
                ++i;
            }
        }
    }
};

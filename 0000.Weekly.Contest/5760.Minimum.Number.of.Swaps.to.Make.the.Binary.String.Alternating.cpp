class Solution {
public:
    int swapNums(string lhs, string rhs) {
        int nums = 0;
        int len = lhs.size();
        for (int i = 0; i < len; ++i) {
            if (lhs[i] != rhs[i]) {
                ++nums;
            }
        }
        return nums / 2;
    }
    
    string constructOne(int n) {
        string relt = "1";
        char prev = '1';
        for (int i = 1; i < n; ++i) {
            if (prev == '1') {
                relt += '0';
                prev = '0';
            } else {
                relt += '1';
                prev = '1';
            }
        }
        return relt;
    }
    
    string constructZero(int n) {
        string relt = "0";
        char prev = '0';
        for (int i = 1; i < n; ++i) {
            if (prev == '0') {
                relt += '1';
                prev = '1';
            } else {
                relt += '0';
                prev = '0';
            }
        }
        return relt;
    }
    
    int minSwaps(string s) {
        int n = s.size();
        int numOfOne = 0;
        int numOfZero = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ++numOfOne;
            } else {
                ++numOfZero;
            }
        }
        
        if (n % 2 == 0) {
            if (numOfOne != numOfZero) {
                return -1;
            }
        } else {
            if (abs(numOfOne - numOfZero) != 1) {
                return -1;
            }
        }
        
        if (numOfOne > numOfZero) {
            string first = constructOne(n);
            return swapNums(s, first);
        } else if (numOfOne < numOfZero) {
            string second = constructZero(n);
            return swapNums(s, second);
        } else {
            string first = constructOne(n);
            string second = constructZero(n);
            return min(swapNums(s, first), swapNums(s, second));
        }

    }
};

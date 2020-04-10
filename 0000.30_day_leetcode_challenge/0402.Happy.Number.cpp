class Solution {
public:
    bool isHappy(int n) {
        vector<int> history;

        while (true) {
            int curSum = getSumDigits(n);
            if (curSum == 1) {
                return true;
            }
            else {
                if (std::find(history.begin(), history.end(), curSum) != history.end()) {
                    return false;
                } else {
                    history.push_back(curSum);
                    n = curSum;
                }
            }
        }
    }
private:
    int getSumDigits(int n) {
        int result = 0;
        while (n != 0) {
            int digit = n % 10;
            result += digit * digit;
            n = n/10;
        }
        return result;
    }
};
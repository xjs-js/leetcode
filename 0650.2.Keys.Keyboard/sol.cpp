class Solution {
private:
    unordered_map<int, int> _memo;
public:
    Solution() {
        _memo[1] = 0;
        _memo[2] = 2;
        _memo[3] = 3;
        _memo[4] = 4;
        _memo[5] = 5;
        _memo[6] = 5;
        _memo[7] = 7;
        _memo[8] = 6;
        _memo[9] = 6;
        _memo[10] = 7;
        _memo[11] = 11;
        _memo[12] = 7;
        _memo[13] = 13;
        _memo[14] = 9;
        _memo[15] = 8;
        _memo[16] = 8;
        _memo[17] = 17;
        _memo[18] = 8;
        _memo[19] = 19;
        _memo[20] = 9;
    }

    int minSteps(int n) {
        if (_memo.find(n) != _memo.end()) {
            return _memo.at(n);
        }

        for (int i = 2; i <= n-1; ++i) {
            if (n % i == 0) {
                int divide = n / i;
                _memo[n] = (i + minSteps(divide));
                return _memo[n];
            }
        }

        _memo[n] = n;
        return _memo[n];
    }
};
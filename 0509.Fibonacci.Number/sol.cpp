/**
 * @date: 2021-04-15 17:56 Thur.
 */

class Solution {
private:
    unordered_map<int, int> _memo;
public:
    int fib(int n) {
        if (_memo.find(n) != _memo.end()) {
            return _memo[n];
        }
        if (n == 0) {
            _memo[0] = 0;
            return 0;
        } else if (n == 1) {
            _memo[1] = 1;
            return 1;
        } else {
            return fib(n-1) + fib(n-2);
        }
    }
};
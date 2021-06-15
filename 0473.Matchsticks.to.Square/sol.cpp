class Solution {
private:
    bool _relt;

public:


    void search(vector<int>& matchsticks, int i, int len, int first, int second, int third, int forth) {
        int n = matchsticks.size();

        if (i == n) {
            if (first == len && second == len && third == len && forth == len) {
                _relt = true;
            }
        } else {
            if (_relt) return;
            
            int cur = matchsticks[i];
            if (first + cur <= len) {
                search(matchsticks, i+1, len , first + cur, second, third, forth);
            }

            if (_relt ) return;

            if (second + cur <= len) {
                search(matchsticks, i+1, len, first, second + cur, third, forth);
            }

            if (_relt) return;

            if (third + cur <= len) {
                search(matchsticks, i+1, len, first, second, third+cur, forth);
            }

            if (_relt) return;

            if (forth + cur <= len) {
                search(matchsticks, i+1, len, first, second, third, forth+cur);
            }
        }
    }


    bool makesquare(vector<int>& matchsticks) {
        _relt = false;
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); ++i) {
            sum += matchsticks[i];
        }

        if (sum % 4 != 0) {
            return false;
        } else {
            int len = sum / 4;

            search(matchsticks, 0, len, 0, 0, 0, 0);
        }

        return _relt;
    }
};

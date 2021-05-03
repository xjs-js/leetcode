class Solution {
private:
    vector<int> _relt;
    bool _hasFound;

    void dfs(string& S, int beg) {
        int n = S.size();
        if (beg == n) {
            if (_relt.size() >= 3) {
                _hasFound = true;
            }
            return ;
        } else {
            for (int i = 1; i <= n-beg; ++i) {
                if (i > 1 && S[beg] == '0') {
                    return ;
                }

                if (i > 10 || (i == 10 && S.substr(beg, i) > "2147483647")) {
                    return ;
                }

                int num = atoi(S.substr(beg, i).c_str());
                if (num < 0) {
                    cout << S.substr(beg, i) << endl;
                }
                if (_relt.size() < 2) {
                    _relt.push_back(num);
                    dfs(S, beg + i);
                    if (_hasFound) {
                        return ;
                    } else {
                        _relt.pop_back();
                    }
                } else {
                    int m = _relt.size();
                    int first = _relt[m - 2];
                    int second = _relt[m - 1];
                    if (num - second == first) {
                        _relt.push_back(num);
                        dfs(S, beg + i);
                        if (_hasFound) {
                            return ;
                        } else {
                            _relt.pop_back();
                        }
                    } else if (first > num - second) {
                        continue;
                    } else {
                        return ;
                    }
                }
            }
        }
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        _hasFound = false;

        int n = S.size();
        // i 表示 序列中 第一个 数字的长度
        dfs(S, 0);

        return _relt;
    }
};



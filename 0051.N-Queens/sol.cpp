class Solution {
private:
    vector<int> _curRelt;
    vector<vector<string>> _relt;
    vector<bool> _choose;
    int _n;
    
    bool isValid(int k) {
        if (_curRelt.size() == 0) {
            return true;
        }
        
        int curRow = _curRelt.size();
        
        for (int i = 0; i < _curRelt.size(); ++i) {
            int prevCol = _curRelt[i];
            if (prevCol == k) {
                return false;
            }
            
            if (abs(curRow - i) == abs(k - prevCol)) {
                return false;
            }
        }
        return true;
    }
    
    
    void search() {
        if (_curRelt.size() == _n) {
            vector<string> tmp;
            string line(_n, '.');
            for (int i = 0; i < _n; ++i) {
                line[_curRelt[i]] = 'Q';
                tmp.push_back(line);
                line[_curRelt[i]] = '.';
            }
            _relt.push_back(tmp);
        } else {
            for (int i = 0; i < _n; ++i) {
                if (_choose[i]) {
                    continue;
                } else {
                    if (isValid(i)) {
                        _choose[i] = true;
                        _curRelt.push_back(i);
                        search();
                        _choose[i] = false;
                        _curRelt.pop_back();
                    }   
                }
            }
        }
    }
    
    
public:
    
    
    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        _choose.resize(n, false);
        search();
        
        return _relt;
    }
};

class Solution {
private:
    vector<vector<int>> _relt;
    int _dire;
    int _row, _col;
    int _num;
    int _r, _c;
    
    void add() {
        if (_r >= 0 && _r <= _row-1 && _c >= 0 && _c <= _col-1) {
            _relt.push_back({_r, _c});
        }
    }
    
    void walk(int step) {
        while (step--) {
            if (_dire == 0) {
                --_r;
            } else if (_dire == 1) {
                ++_c;
            } else if (_dire == 2) {
                ++_r;
            } else if (_dire == 3) {
                --_c;
            }
            
            add();
        }
    }
    
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        _dire = 1;

        _row = rows;
        _col = cols;
        _r = rStart;
        _c = cStart;
        
        int step = 1;
        _relt.push_back({_r, _c});
        while (_relt.size() != _row * _col) {
            walk(step);
            _dire = (_dire + 1) % 4;
            walk(step);
            _dire = (_dire + 1) % 4;
            ++step;
        }
        
        return _relt;
    }
};

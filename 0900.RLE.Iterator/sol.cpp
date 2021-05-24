class RLEIterator {
private:
    vector<int> _arr;
    int _idx;
    
public:
    RLEIterator(vector<int>& encoding) : _arr(encoding), _idx(0) {
        
    }
    
    int next(int n) {
        int m = _arr.size();

        while (n) {
            if (_idx > m - 2) {
                return -1;
            }
            
            int curTimes = _arr[_idx];
            if (curTimes > n) {
                _arr[_idx] = curTimes - n;
                return _arr[_idx+1];
            } else if (curTimes == n) {
                int relt = _arr[_idx+1];
                _idx += 2;
                return relt;
            } else {
                n -= curTimes;
                _idx += 2;
            }
        }
        
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

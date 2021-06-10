class MyCalendar {
private:
    set<pair<int, int>> _memo;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (_memo.empty()) {
            _memo.insert({start, end});
            return true;
        }
        
        auto it = _memo.begin();
        while (it != _memo.end()) {
            int s = (*it).first;
            int e = (*it).second;
            ++it;
            
            if (end <= s) {
                continue;
            } else if (start >= e) {
                continue;
            } else {
                return false;
            }
            
        }
        
        _memo.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

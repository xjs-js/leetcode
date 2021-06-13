class RecentCounter {
private:
    deque<int> _dq;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        while (!_dq.empty() && _dq.front() < t-3000) {
            _dq.pop_front();
        }

        _dq.push_back(t);
        return _dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

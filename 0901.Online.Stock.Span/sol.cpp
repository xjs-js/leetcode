class StockSpanner {
private:
    vector<int> _relt;
    vector<int> _price;
    stack<int> _sk; 
    int _count;
public:
    StockSpanner() : _count(0) {

    }
    
    int next(int price) {
        int curRelt = 1;
        while (!_sk.empty() &&  _price[_sk.top()] <= price) {
            curRelt += _relt[_sk.top()];
            _sk.pop();
        }
        _sk.push(_count);
        _relt.push_back(curRelt);
        _price.push_back(price);
        ++_count;
        return curRelt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

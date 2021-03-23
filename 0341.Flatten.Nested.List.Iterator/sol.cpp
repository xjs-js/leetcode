/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */



class NestedIterator {
    vector<int> _value;
    size_t _curIndex;
    size_t _valueLen;
private:
    void InsertValue(vector<NestedInteger>& nestedList) {
        for (int i = 0; i < nestedList.size(); ++i) {
            NestedInteger& Integer = nestedList.at(i);
            if (Integer.isInteger()) {
                _value.emplace_back(Integer.getInteger());
            } else {
                InsertValue(Integer.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        InsertValue(nestedList);
        _valueLen = _value.size();
        if (_valueLen > 0) {
            _curIndex = 0;
        }
    }
    
    int next() {
        return _value[_curIndex];
    }
    
    bool hasNext() {
        return (_curIndex >= 0) && (_curIndex < _valueLen);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
class MyLinkedList {
private:
    ListNode* _dumbHead;
    ListNode* _tail;
    int _count;
private:
    // -1 <= index < _count
    ListNode* getPointer(int index) {
        if (_dumbHead == nullptr) return nullptr;
        if (index < -1 || index >= _count) return nullptr;

        if (index == -1)
            return _dumbHead;
        else {
            if (ListNode* p = _dumbHead->next) {
                while (p && index--) {
                    p = p->next;
                }
                return p;
            }
        }

        return nullptr;
    }
public:
    MyLinkedList() : _count(0) {
        _dumbHead = new ListNode(-1, nullptr);
        _tail = _dumbHead;
    }

    // 0 <= index < _count
    int get(int index) {
        if (index < 0 || index >= _count)
            return -1;

        if (ListNode* p = getPointer(index)) {
            return p->val;
        }

        return -1;
    }

    void addAtHead(int val) {
        if (_dumbHead == nullptr) return;
        
        if (ListNode* newNode = new ListNode(val, _dumbHead->next)) {
            _dumbHead->next = newNode;
            ++_count;
            if (_count == 1)
                _tail = newNode;
        }
    }
    
    void addAtTail(int val) {
        if (_tail) {
            _tail->next = new ListNode(val, nullptr);
            _tail = _tail->next;
            ++_count;
        }
    }

    // 0 <= index <= _count
    void addAtIndex(int index, int val) {
        if (0 <= index && index <= _count) {
            if (ListNode *p = getPointer(index - 1)) {
                if (ListNode *newNode = new ListNode(val, p->next)) {
                    p->next = newNode;
                    if (index == _count) {
                        _tail = newNode;
                    }
                    ++_count;
                }
            }
        }
    }

    // 0 <= index < _count;
    void deleteAtIndex(int index) {
        if (0 <= index && index < _count) {
            if (ListNode* p = getPointer(index - 1)) {
                if (ListNode* toDelete = p->next) {
                    p->next = toDelete->next;
                    delete toDelete;
                    if (index == _count - 1) {
                        _tail = p;
                    }
                    --_count;
                }
            }
        }
    }
};
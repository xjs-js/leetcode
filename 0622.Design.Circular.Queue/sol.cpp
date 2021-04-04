/**
 * @date: 2021-04-04 19:35
 * @note: 吃完晚饭回来
 */

class MyCircularQueue {
private:
    int* _nums; // 存放数据的数组
    int  _cap;  // 容量
    int  _front; // 头指针
    int  _rear; // 尾指针
public:
    MyCircularQueue(int k) : _cap(k+1), _front(0), _rear(0) {
        _nums = new int[k+1];
    }

    ～MyCircularQueue() {
        delete[] _nums;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            _nums[_rear] = value;
            _rear = (_rear + 1) % _cap;
            return true;
        }

        return false;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            _front = (_front + 1) % _cap;
            return true;
        }

        return false;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return _nums[_front];
        }
    }
    
    int Rear() {
       if (isEmpty()) {
            return -1;
       } else {
            if (_rear == 0) {
                return _nums[_cap-1];
            } else {
                return _nums[_rear - 1];
            }
       }
    }
    
    bool isEmpty() {
        return (_front == _rear);
    }
    
    bool isFull() {
        return (_rear + 1) % _cap == _front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

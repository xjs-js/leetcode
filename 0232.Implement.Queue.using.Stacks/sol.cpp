/**
 * @date: 2021-04-01 22:37
 * @note: 写完就去🛀
 */


class MyQueue {
private:
    stack<int> left;
    stack<int> right;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        left.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (right.empty()) {
            while (!left.empty()){
                int top = left.top();
                right.push(top);
                left.pop();
            }
        }

        int top = right.top();
        right.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (right.empty()) {
            while (!left.empty()) {
                int top = left.top();
                right.push(top);
                left.pop();
            }
        }

        return right.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (right.empty()) {
            return left.empty();
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

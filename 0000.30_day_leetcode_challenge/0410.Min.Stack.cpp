class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        m_stack.push_back(x);
        if (m_curMin.size() == 0) {
            m_curMin.push_back(x);
        } else {
            int last_min = m_curMin[m_curMin.size() - 1];
            if (x < last_min) {
                m_curMin.push_back(x);
            } else {
                m_curMin.push_back(last_min);
            }
            
        }
    }
    
    void pop() {
        m_stack.pop_back();
        m_curMin.pop_back();
    }
    
    int top() {
        return m_stack[m_stack.size() - 1];
    }
    
    int getMin() {
        return m_curMin[m_curMin.size() - 1];
    }

private:
    vector<int> m_stack;  // stack
    vector<int> m_curMin; // stores the minimum till current index
};
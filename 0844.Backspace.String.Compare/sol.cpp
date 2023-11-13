class Solution {
private:
    void simulation(stack<char>& sk, string s) {
        for (char c : s) {
            if (c != '#') {
                sk.push(c);
            } else {
                if (!sk.empty()) {
                    sk.pop();
                }
            }
        }
    }

    bool isSameStack(stack<char>& left, stack<char>& right) {
        while(!left.empty() && !right.empty()) {
            if (left.top() != right.top()) {
                return false;
            }
            left.pop();
            right.pop();
        }

        return left.empty() && right.empty();
    }

public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack;
        stack<char> t_stack;

        simulation(s_stack, s);
        simulation(t_stack, t);

        return isSameStack(s_stack, t_stack);
    }
};

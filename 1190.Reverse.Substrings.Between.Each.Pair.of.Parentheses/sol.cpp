class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> sk; // 存放左括号的下标
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sk.push(i);
            } else if (s[i] == ')') {
                int top = sk.top();
                sk.pop();
                reverse(s.begin() + top, s.begin() + i);
            }
        }
        
        string relt;
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                relt += s[i];
            }
        }
        
        return relt;
    }
};

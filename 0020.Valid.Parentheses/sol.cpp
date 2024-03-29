// 2023/11/21 20:08
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (c == ')')
                    if (!st.empty() && st.top() == '(') st.pop();
                    else                                return false;
                if (c == '}')
                    if (!st.empty() && st.top() == '{') st.pop();
                    else                                return false;
                if (c == ']')
                    if (!st.empty() && st.top() == '[') st.pop();
                    else                                return false;
            }
        }
        return st.empty();
    }
};

#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for (char& c : s) {
            switch (c)
            {
            case '(':
                sk.push(')');
                break;
            case '{':
                sk.push('}');
                break;
            case '[':
                sk.push(']');
                break;
            case ')':
            case ']':
            case '}':
                if (sk.size() == 0 || c != sk.top())
                    return false;
                else {
                    sk.pop();
                }
            default:
                break;
            }
        }
        return sk.size() == 0;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s);
    return 0;
}

/**
 * @date: 2021-04-03 22:51
 * @note: 这题简单，直接用栈就行
 */



class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;

        int* ans = new int[s.size()];
        for (int i = 0; i < s.size(); ++i) {
            ans[i] = 0;
        }


        stack<int> sk;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (c == '(') {
                sk.push(i);
            } else if (c == ')') {
                if (!sk.empty()) {
                    int top = sk.top();
                    sk.pop();
                    int cur = i - top + 1;
                    if (top != 0) {
                        cur += ans[top-1];
                    }
                    ans[i] = cur;
                    result = max(result, cur);
                }
            }

        }
        
        delete[] ans;
        return result;
    }
};

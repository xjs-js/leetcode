/**
 * @date: 2021-03-20
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> sk;
        sk.push(atoi(tokens[0].c_str()));

        for (int i = 1; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();

                sk.push(num2 + num1);
            } else if (tokens[i] == "-") {
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();

                sk.push(num2 - num1);

            } else if (tokens[i] == "*") {
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();

                sk.push(num2 * num1);

            } else if (tokens[i] == "/") {
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();

                sk.push(num2 / num1);
            } else {
                sk.push(atoi(tokens[i].c_str()));
            }
        }

        return sk.top();
    }
};